/*
 * 题目3：(google笔试题)：有四个线程1、2、3、4。线程 1 的功能就是输出1，线程2的功能就是输出2，以此类推.........现在有四个文件ABCD。初始都为空。现要让四个文件呈如下格式：

A：1 2 3 4 1 2....

B：2 3 4 1 2 3....

C：3 4 1 2 3 4....

D：4 1 2 3 4 1....
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
#include <condition_variable>
using namespace std;

const string filename = "./test";
condition_variable cv;
std::mutex mtx;

int visited[] = {4, 1, 2, 3};

ofstream f1(filename + "_A.txt");
ofstream f2(filename + "_B.txt");
ofstream f3(filename + "_C.txt");
ofstream f4(filename + "_D.txt");

ofstream *file[4];

void solve(const int x, int gg) {
    while(gg--) {
        for( int i = 0; i < 4; i++ ) {
            
            std::unique_lock<std::mutex> locker(mtx);

            if(x == 1) {
                cv.wait(locker, [&]{
                   return visited[i]  = 4;    
                });
                (*file[i]) << 1;
                visited[i] = 1;
                locker.unlock();
                cv.notify_all();
            }else if(x == 2) {
                cv.wait(locker, [&]{
                    return visited[i] == 1;
                });
                (*file[i]) << 2;
                visited[i] = 2;
                locker.unlock();
                cv.notify_all();
            }else if(x == 3) {
                cv.wait(locker, [&]{
                   return visited[i] == 2;    
                });
                (*file[i]) << 3;
                visited[i] = 3;
                locker.unlock();
                cv.notify_all();
            }else {
                cv.wait(locker, [&]{
                    return visited[i] == 3;
                });
                (*file[i]) << 4;
                visited[i] = 4;
                locker.unlock();
                cv.notify_all();
            }
        }
    }
}

int main()
{
    file[0] = &f1;
    file[1] = &f2;
    file[2] = &f3;
    file[3] = &f4;

    thread t1(solve, 1, 10);
    thread t2(solve, 2, 10);
    thread t3(solve, 3, 10);
    solve(4, 10);

    t1.join();
    t2.join();
    t3.join();

    for(int i = 0; i < 4; i++)
        file[i]->close();

    return 0;
}
