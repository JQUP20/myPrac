/*
 * 题目1：子线程循环 10 次，接着主线程循环 100 次，接着又回到子线程循环 10 次，接着再回到主线程又循环 100 次，如此循环50次，试写出代码
*/

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

const int count = 50;
int flag = 10;
std::mutex mtx;

void fun(const int num, const string &str) {
    for(int i=  0; i < count; ++i) {
        while(num != flag) std::this_thread::yield();
        mtx.lock();
        for(int j = 0; j < num; ++j) {
            cout << str << endl;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
        flag = (flag == 10 ? 100 : 10);
        mtx.unlock();
    }
}


int main(void) {
    auto start = std::chrono::high_resolution_clock::now();
    thread child(fun, 10, "child");
    fun(100, "father");
    child.join();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end -start;
    cout << elapsed.count() << endl;
}
