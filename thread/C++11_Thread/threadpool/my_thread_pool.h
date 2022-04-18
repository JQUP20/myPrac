#ifndef __MY_THREAD_POOL__
#define __MY_THREAD_POOL__

#include <vector>
#include <queue>
#include <atomic>
#include <future>
#include <condition_variable>
#include <thread>
#include <functional>
#include <stdexcept>

using namespace std;

#define THREADPOOL_MAX_NUM 16

class ThreadPool{
public:
    ThreadPool(unsigned short size = 4) { addThread(size); }

    ~ThreadPool(){
        m_run = false;
        m_task_cv.notify_all();
        for(thread& thread : m_pool) {
            if(thread.joinable())
                thread.join();
        }
    }

    template<class F, class... Args>
    auto commit(F&& f, Args&&... args) -> future<decltype(f(args...))>
    {
        if(!m_run)
            throw runtime_error("commit on ThreadPool is stopped.");

        using RetType = decltype(f(args...));
        auto task = make_shared<packaged_task<RetType()>>( bind(forward<F>(f), forward<Args>(args)...) );
        future<RetType> future = task->get_future();
        {
            lock_guard<mutex> lock{ m_lock };
            m_tasks.emplace([task](){
                        (*task)();
                    });
        }
        
        m_task_cv.notify_one();

        return future;
    }

    int idleThreadCount() { return m_idleThreadNum; }

    int threadCount()   { return m_pool.size(); }

    void addThread(unsigned short size)
    {
        for(; m_pool.size() < THREADPOOL_MAX_NUM && size > 0; --size)
        {
            m_pool.emplace_back( [this]{
                    while(m_run)
                    {
                        Task task;
                        {
                            unique_lock<mutex> lock{ m_lock };
                            m_task_cv.wait(lock, [this]{            //wait直到有task
                                        return !m_run || !m_tasks.empty();        
                            });
                            if(!m_run && m_tasks.empty())
                                return;
                            task = move(m_tasks.front());           //按先进先出从队列中取一个task

                            m_tasks.pop();
                        }
                        m_idleThreadNum--;
                        task();             //执行任务
                        m_idleThreadNum++;
                    }
            });
            m_idleThreadNum++;
        }
    }

private:
    using Task = function<void()>;
    vector<thread> m_pool;
    queue<Task> m_tasks;
    mutex m_lock;
    condition_variable m_task_cv;
    atomic<bool> m_run{ true };
    atomic<int> m_idleThreadNum{0};
};

#endif
