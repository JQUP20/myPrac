//循环创建子线程，并且打印是第几个子线程
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <pthread.h>
using namespace std;

void *mythread(void *arg)
{
    int i = *(int *)arg;
    cout << i << "child thread, pid --> " << getpid() << " id --> " << pthread_self() << endl; 
    sleep(5);
}

int main()
{
    int ret;
    int i = 0;
    int n = 5;
    int arr[5];
    pthread_t thread[5];
    for(i = 0; i < 5; i++)
    {
        arr[i] = i;
        ret = pthread_create(&thread[i], nullptr, mythread, &arr[i]);

    }

    cout << "main thread, pid --> " << getpid() << "id --> " << pthread_self() << endl;

    sleep(10);

    return 0;
}
