#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

std::condition_variable cv;
std::mutex metx;
int g_Flag = 0;
int cnt = 0;
bool flag = false;

int main(void) {
    thread t1([&]{
        std::unique_lock<std::mutex> lk(metx);
        cout << "this is thread1\n";
        g_Flag = 1;
        ++cnt;
        cv.wait(lk, [&]{{
            return flag;
        }});
        cout << "thread1 exit\n";
    });

    thread t2([&]{
        std::unique_lock<std::mutex> lk(metx);
        cout << "this is thread2\n";
        g_Flag = 2;
        cnt++;
        flag = true;
        cv.notify_all();
        cout << "thread2 exit\n";
    });

    t1.detach();//分离线程
    t2.detach();

    std::unique_lock<std::mutex> lc(metx);
    cv.wait(lc, [&]{
        return cnt >= 2;
    });
    cout << "main thread exit\n";

    return 0;
}

