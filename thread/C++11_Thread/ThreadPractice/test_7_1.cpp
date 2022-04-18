#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <future>
using namespace std;

atomic<int> g_Flag(0), cnt(0);

void thread1(std::future<int> fu) {
    cout << "this is thread1\n";
    g_Flag = 1;
    ++cnt;
    fu.get();//线程1阻塞至线程2设置共享状态, get等待异步操作结束并返回结果
    cout << "thread1 exit\n";
}

void thread2(std::promise<int> pro) {
    cout << "this is thread2\n";
    g_Flag = 2;
    ++cnt;
    cout << "thread2 exit\n";
    pro.set_value(1);//设置共享值
}

int main(void) {
    std::promise<int> prom;//创建一个promise对象
    std::future<int> fu = prom.get_future();//获得promise内部的future,fut将和prom共享prom中的共享状态

    std::thread t1(thread1, std::move(fu));//通过fut在线程1中得到线程2的状态
    std::thread t2(thread2, std::move(prom));//通过prom设置线程2中的共享状态

    t1.detach();
    t2.detach();

    while(cnt < 2);
    cout << "main thread exit\n";

    return 0;
}


