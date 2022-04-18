/*
 *STL 中的每个容器类都有各自的特点，分别适用于不同的情况。选择合适的容器类
会提高程序的运行速度，反之则会使运行速度比较低，有时候对比效果十分显著。以下
程序表明，采用 deque 的“头部插入操作”明显快于对应的 vector 操作
*/

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
using namespace std;

int main()
{
    //vector的插入操作
    typedef vector<int> int_vector;
    int_vector v;
    time_t start_time;
    start_time = time(&start_time);
    for(int i = 0; i <= 200000; i++)
    {
        v.insert(v.begin(), 1);
    }
    time_t mid_time;
    mid_time = time(&mid_time);
    cout << mid_time - start_time << endl;

    //deque的插入操作
    typedef deque<int> int_deque;
    int_deque dq;
    for(int j = 0; j <= 200000; j++)
    {
        dq.insert(dq.begin(), 1);
    }
    time_t end_time;
    end_time = time(&end_time);
    cout << end_time - mid_time << endl;
    return 0;
}
