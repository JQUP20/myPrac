/*
 *屏障
屏障（barrier)是用户协调多个线程并行工作的同步机制。屏障允许每个线程等待，直到所有的合作线程都到达某一点，然后所有线程都从该点继续执行。pthread_join函数就是一种屏障，允许一个线程等待，直到另一个线程退出。但屏障对象的概念更广，允许任意数量的线程等待，直到所有的线程完成处理工作，而线程不需要退出，当所有的线程达到屏障后可以接着工作。
// 创建屏障
int pthread_barrier_init(pthread_barrier_t *barrier,const pthread_barrrierattr_t *attr,unsigned int count)

// 阻塞等待，直到所有线程都到达
int pthread_barrier_wait(pthread_barrier_t *barrier)
*/

#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

pthread_barrier_t barrier;

void *go(void *arg){
    sleep(rand() % 10);
    cout << pthread_self() << " is arrived..." << endl;
    pthread_barrier_wait(&barrier);
    cout << pthread_self() << " go shopping..." << endl;
}

int main(){
    pthread_barrier_init(&barrier, nullptr, 3);

    pthread_t t1, t2, t3;
    pthread_create(&t1 , nullptr, &go, nullptr);
    pthread_create(&t2 , nullptr, &go, nullptr);
    pthread_create(&t3 , nullptr, &go, nullptr);

    pthread_join(t1, nullptr);

    return 0;
}
