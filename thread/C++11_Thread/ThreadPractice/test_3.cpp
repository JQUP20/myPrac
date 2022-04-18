/*
 *题目2：编写一个程序，开启3个线程，这3个线程的ID分别为A、B、C，每个线程将自己的ID在屏幕上打印10遍，要求输出结果必须按ABC的顺序显示；如：ABCABC….依次递推
 */

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int main()
{
    std::mutex mtx;
    int cnt = 0;
    auto work = [&](char ch, int num) {
        while(num--) {
            while(ch != cnt + 'A') std::this_thread::yield();
            std::unique_lock<std::mutex> locker(mtx);
            cout << ch; 
            cnt = (cnt + 1) % 3;
            //cout << endl;
            if(cnt  == 2)
                cout << endl;
            locker.unlock();
        }
    };

    thread t1(work, 'A', 10);
    thread t2(work, 'B', 10);
    work('C', 10);

    t1.join();
    t2.join();

    return 0;
}
