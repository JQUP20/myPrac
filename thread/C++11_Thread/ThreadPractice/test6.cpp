/*
 * 线程安全的 queue

STL 中的 queue 是非线程安全的，一个组合操作：front();  pop() 先读取队首元素然后删除队首元素，若是有多个线程执行这个组合操作的话，可能会发生执行序列交替执行，导致一些意想不到的行为。因此需要重新设计线程安全的 queue 的接口
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <chrono>
#include <condition_variable>
using namespace std;

template <typename T>
class thread_safe_queue{
private:
    std::condition_variable cv;
    std::queue<T> que;
    std::mutex mtx;

public:
    thread_safe_queue() = default;
    thread_safe_queue(const std::queue<T> q) : que(q) {}
    thread_safe_queue(const thread_safe_queue &tsf) {
        std::unique_lock<std::mutex> lk(mtx);
        que = tsf.que;
    }
    ~thread_safe_queue() = default;

    void push(const T &value) {
        std::unique_lock<std::mutex> lk(mtx);
        que.push(value);
        lk.unlock();
        cv.notify_all();
    }

    T pop(void) {
        std::unique_lock<std::mutex> lk(mtx);
        cv.wait(lk, [&]{
            return bool(!que.empty());
        });
        T value = que.front();
        que.pop();
        return value;
    }

    bool empty(void) {
        std::unique_lock<std::mutex> lk(mtx);
        return que.empty();
    }
};

thread_safe_queue<int> q;
std::mutex mtx;

int main(void) {

    auto push_value = [&]{
        for(int i = 0; i < 100; ++i) {
            q.push(i);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    };

    auto pop_value = [&]{
        while(1) {
            while(!q.empty()) {
                std::unique_lock<std::mutex> lk(mtx);
                cout << q.pop() << '\n';
            }
        }
    };

    thread push_thread1(push_value);
    thread pop_thread1(pop_value);
    thread pop_thread2(pop_value);
    thread pop_thread3(pop_value);

    push_thread1.join();
    pop_thread1.join();
    pop_thread2.join();
    pop_thread3.join();

    return 0;
}


