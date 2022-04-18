/*
 * 题目4：有一个写者很多读者，多个读者可以同时读文件，但写者在写文件时不允许有读者在读文件，同样有读者读时写者也不能写
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
#include <stdio.h>
#include <condition_variable>
using namespace std;

const string filename = "c36.txt";
std::condition_variable cv;
std::mutex mtx;
int cnt = 0;

ifstream in(filename);
ofstream out(filename, ios::app);

void write() {
    char ch;
    while(true) {
        std::unique_lock<std::mutex> lk(mtx);
        ch = getchar();
        out << ch;
        ++cnt;
        lk.unlock();
        cv.notify_all();
    }
}

void read() {
    char ch;
    while(true) {
        std::unique_lock<std::mutex> lk(mtx);
        cv.wait(lk, [&]{
            return cnt > 0;
        });
        in >> ch;
        cout << "cout: " << ch << endl;
        --cnt;
    }
}

int main(void) {
    cnt = in.tellg();

    std::thread tw(write);
    std::thread tr1(read);
    std::thread tr2(read);
    std::thread tr3(read);

    tw.join();
    tr1.join();
    tr2.join();
    tr3.join();

    in.close();
    out.close();

    return 0;
}

