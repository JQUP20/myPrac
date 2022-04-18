#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
using namespace std;

condition_variable cv;
std::mutex mtx;
int cnt = 0;

void work(char ch, int num)
{
    while(num--)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        unique_lock<std::mutex> locker(mtx);
        cv.wait(locker, [&]{
            return 'A' + cnt == ch;
        });
        cout << ch;
        cnt = (cnt + 1) % 3;
        locker.unlock();
        cv.notify_one();
    }
}

int main()
{
    thread t1(work, 'A', 10);
    thread t2(work, 'B', 10);
    work('C', 10);

    t1.join();
    t2.join();

    return 0;
}
