#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

const int count = 50;
int flag = 10;
condition_variable cv;
std::mutex mtx;

void fun(const int num, const string &str) {
    for(int i = 0; i < count; ++i) {
        unique_lock<std::mutex> locker(mtx);
        cv.wait(locker, [&] {
            return num == flag;
        });
        for(int j = 0; j < num; j++) {
            cout << str << endl;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
        flag = (flag == 10 ? 100 : 10);
        mtx.unlock();
        cv.notify_one();
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    thread child(fun, 10, "child");
    fun(100, "father");
    child.join();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    cout << elapsed.count() << endl;

    return 0;
}
