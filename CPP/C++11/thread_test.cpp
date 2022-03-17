#include <iostream>
#include <vector>
#include <functional>
#include <memory>
#include <memory>
#include <list>
#include <mutex>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <thread>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <algorithm>

namespace thread_ {
    
    std::atomic<int> global_counter(0);

    static void increase_global(int n)
    {
        for(int i = 0; i < n; i++)
            ++global_counter;
    }

    static void increase_reference(std::atomic<int>& variable, int n)
    {
        for(int i = 0; i < n; i++)
            ++variable;
    }

    struct C : std::atomic<int> {
        C() : std::atomic<int>(0) {}
        void increase_member(int n)
        {
            for(int i = 0; i < n; i++)
                fetch_add(1);
        }
    };

    int test_thread_thread()
    {
        std::vector<std::thread> threads;

        std::cout << "increase global counter with 10 threads...\n";
        for(int i = 1; i <= 10; ++i)
            threads.push_back(std::thread(increase_global, 1000));

        std::cout << "increase counter (foo) with 10 threads using reference...\n";
        std::atomic<int> foo(0);
        for (int i = 1; i <= 10; ++i)
            threads.push_back(std::thread(increase_reference, std::ref(foo), 1000));

        std::cout << "increase counter (bar) with 10 threads using member...\n";
        C bar;
        for (int i = 1; i <= 10; ++i)
            threads.push_back(std::thread(&C::increase_member, std::ref(bar), 1000));

        std::cout << "synchronizing all threads...\n";
        for (auto& th : threads) th.join();

        std::cout << "global_counter: " << global_counter << '\n';
        std::cout << "foo: " << foo << '\n';
        std::cout << "bar: " << bar << '\n';

        return 0;
    }


template<typename T>
class SyncQueue {
public:
	SyncQueue(int maxSize) :m_maxSize(maxSize), m_needStop(false) {}

	void Put(const T&x) { Add(x); }
	void Put(T&&x) { Add(std::forward<T>(x)); }

	void Take(std::list<T>& list)
	{
		std::unique_lock<std::mutex> locker(m_mutex);
		m_notEmpty.wait(locker, [this] {return m_needStop || NotEmpty(); });

		if (m_needStop) return;
		list = std::move(m_queue);
		m_notFull.notify_one();
	}

	void Take(T& t)
	{
		std::unique_lock<std::mutex> locker(m_mutex);
		m_notEmpty.wait(locker, [this] {return m_needStop || NotEmpty(); });

		if (m_needStop) return;
		t = m_queue.front();
		m_queue.pop_front();
		m_notFull.notify_one();
	}

	void Stop()
	{
		{
			std::lock_guard<std::mutex> locker(m_mutex);
			m_needStop = true;
		}
		m_notFull.notify_all();
		m_notEmpty.notify_all();
	}

	bool Empty()
	{
		std::lock_guard<std::mutex> locker(m_mutex);
		return m_queue.empty();
	}

	bool Full()
	{
		std::lock_guard<std::mutex> locker(m_mutex);
		return m_queue.size() == m_maxSize;
	}

	size_t Size()
	{
		std::lock_guard<std::mutex> locker(m_mutex);
		return m_queue.size();
	}

	int Count()
	{
		return m_queue.size();
	}

private:
	bool NotFull() const
	{
		bool full = m_queue.size() >= m_maxSize;
		if (full)
			std::cout << "full, waiting, thread id: " << std::this_thread::get_id() << std::endl;
		return !full;
	}

	bool NotEmpty() const
	{
		bool empty = m_queue.empty();
		if (empty)
			std::cout << "empty,waiting, thread id: " << std::this_thread::get_id() << std::endl;
		return !empty;
	}

	template<typename F>
	void Add(F&&x)
	{
		std::unique_lock< std::mutex> locker(m_mutex);
		m_notFull.wait(locker, [this] {return m_needStop || NotFull(); });
		if (m_needStop) return;

		m_queue.push_back(std::forward<F>(x));
		m_notEmpty.notify_one();
	}

private:
	std::list<T> m_queue; //缓冲区
	std::mutex m_mutex; //互斥量和条件变量结合起来使用
	std::condition_variable m_notEmpty;//不为空的条件变量
	std::condition_variable m_notFull; //没有满的条件变量
	int m_maxSize; //同步队列最大的size
	bool m_needStop; //停止的标志
};

const int MaxTaskCount = 100;
class ThreadPool {
public:
	using Task = std::function<void()>;
	ThreadPool(int numThreads = std::thread::hardware_concurrency()) : m_queue(MaxTaskCount)
	{
		Start(numThreads);
	}

	~ThreadPool(void)
	{
		//如果没有停止时则主动停止线程池
		Stop();
	}

	void Stop()
	{
		std::call_once(m_flag, [this] {StopThreadGroup(); }); //保证多线程情况下只调用一次StopThreadGroup
	}

	void AddTask(Task&&task)
	{
		m_queue.Put(std::forward<Task>(task));
	}

	void AddTask(const Task& task)
	{
		m_queue.Put(task);
	}

private:
	void Start(int numThreads)
	{
		m_running = true;
		//创建线程组
		for (int i = 0; i <numThreads; ++i) {
			m_threadgroup.push_back(std::make_shared<std::thread>(&ThreadPool::RunInThread, this));
		}
	}

	void RunInThread()
	{
		while (m_running) {
			//取任务分别执行
			std::list<Task> list;
			m_queue.Take(list);

			for (auto& task : list) {
				if (!m_running)
					return;

				task();
			}
		}
	}

	void StopThreadGroup()
	{
		m_queue.Stop(); //让同步队列中的线程停止
		m_running = false; //置为false，让内部线程跳出循环并退出

		for (auto thread : m_threadgroup) { //等待线程结束
			if (thread)
				thread->join();
		}
		m_threadgroup.clear();
	}

	std::list<std::shared_ptr<std::thread>> m_threadgroup; //处理任务的线程组
	SyncQueue<Task> m_queue; //同步队列
	std::atomic_bool m_running; //是否停止的标志
	std::once_flag m_flag;
};

void testThdPool()
{
	ThreadPool pool; bool runing = true;

	std::thread thd1([&pool, &runing] {
		while (runing) {
			std::cout << "produce " << std::this_thread::get_id() << std::endl;

			pool.AddTask([] {
				std::cout << "consume " << std::this_thread::get_id() << std::endl;
			});
		}
	});


	std::this_thread::sleep_for(std::chrono::seconds(10));
	runing = false;
	pool.Stop();

	thd1.join();
	getchar();
}

}
int main()
{
//    thread_::test_thread_thread();
    thread_::testThdPool();

    return 0;
}

