/*
 * 条件变量
条件变量可以让调用线程在满足特定条件的情况下运行，不满足条件时阻塞等待被唤醒，必须与互斥锁搭配使用。

条件变量常用于生产者与消费者模型。

相关方法：

pthread_cond_t cond=PTHREAD_COND_INITIALIZER; // 创建条件变量，一个互斥锁可以对应多个条件变量

int pthread_cond_wait (pthread_cond_t* cond,pthread_mutex_t* mutex); // 阻塞等待条件满足，同时释放互斥锁mutex

int pthread_cond_timedwait (pthread_cond_t* cond,
    pthread_mutex_t* mutex,
    const struct timespec* abstime); // 带超时的阻塞等待条件满足，同时释放互斥锁mutex

// 从条件变量cond中唤出一个线程，令其重新获得原先的互斥锁
// 被唤出的线程此刻将从pthread_cond_wait函数中返回，但如果该线程无法获得原先的锁，则会继续阻塞在加锁上。
int pthread_cond_signal (pthread_cond_t* cond);

// 从条件变量cond中唤出所有线程
int pthread_cond_broadcast (pthread_cond_t* cond);
*/

#include <iostream>
#include <unistd.h>
#include <pthread.h>
using namespace std;

int max_buffer=10;
int count = 0;

pthread_mutex_t  mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t notempty = PTHREAD_COND_INITIALIZER;
pthread_cond_t notfull = PTHREAD_COND_INITIALIZER;

void *produce(void *args) {
    while(1) {
        pthread_mutex_lock(&mutex);
        while(count == max_buffer){
            cout << "buffer is full, wait..." << endl;
            pthread_cond_wait(&notfull, &mutex);
        }
        cout << "child thread, id --> " << pthread_self() << endl;
        cout << "produce ..." << endl;
        count++;
        sleep(1);
        pthread_cond_signal(&notempty);
        pthread_mutex_unlock(&mutex);
    }
}


void *consumer(void *args) {
    while(1) {
        pthread_mutex_lock(&mutex);
        while(count == 0) {
            cout << "buffer is empty, wait...\n" << endl;
            pthread_cond_wait(&notempty, &mutex);
        }
        cout << "consumer ..." << endl;
        count--;
        sleep(1);
        pthread_cond_signal(&notfull);
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t t1, t2, t3, t4;
    pthread_create(&t1, nullptr, &produce, nullptr);
    pthread_create(&t2, nullptr, &produce, nullptr);

    pthread_create(&t3, nullptr, &consumer, nullptr);
    pthread_create(&t4, nullptr, &consumer, nullptr);

    pthread_join(t1, nullptr);

    return 0;
}
