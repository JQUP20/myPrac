#include "my_thread_pool.h"
#include <iostream>

void func()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout<<"worker thread ID:"<<std::this_thread::get_id()<<std::endl;
}

int main()
{
    ThreadPool pool(4);
    //for(int i = 0; i < 100; i++)
    while(1)
    {
        pool.commit(func);
    }
}


