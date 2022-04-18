#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
using namespace std;

condition_variable cv;
std::mutex mtex;
int cnt = 0;

void work(char ch, int num) {
    while(num--) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        unique_lock<std::mutex> lk(mtex);
        cv.wait(lk, [&]{
            return 'A' + cnt == ch;
        });
        cout << ch;
        cnt = (cnt + 1) % 3;
        lk.unlock();
        cv.notify_one();
    }
}

int main(void) {
    thread t1(work, 'A', 10);
    thread t2(work, 'B', 10);
    work('C', 10);

    t1.join();
    t2.join();

    return 0;
}
