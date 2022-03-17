/*
 * 读写锁
读写锁可以有三种状态：读模式下加锁状态，写模式下加锁状态，不加锁状态。一次只有一个线程可以占有写模式的读写锁，但是多个线程可以同时占有读模式的读写锁。读写锁也叫做共享-独占锁，当读写锁以读模式锁住时，它是以共享模式锁住的，当它以写模式锁住时，它是以独占模式锁住的，读读共享，读写互斥。

相关方法：

// 创建读写锁
pthread_rwlock_t rwlock=PTHREAD_RWLOCK_INITIALIZER;

int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock); // 加读锁，阻塞
int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock); // 加写锁，阻塞
int pthread_rwlock_unlock(pthread_rwlock_t *rwlock); // 释放读锁或者写锁

int pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock); // 尝试加读锁，非阻塞
int pthread_rwlock_trywrlock(pthread_rwlock_t *rwlock); // 尝试加写锁，非阻塞
*/

#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;

void *read(void *arg) {
    while(1) {
        pthread_rwlock_rdlock(&rwlock);
        cout << "read message" << endl;
        sleep(1);
        pthread_rwlock_unlock(&rwlock);
        sleep(1);
    }
}

void *write(void *arg) {
    while(1) {
        pthread_rwlock_wrlock(&rwlock);
        cout << "write message.\n" << endl;
        sleep(1);
        pthread_rwlock_unlock(&rwlock);
        sleep(1);
    }
}

int main(){
    pthread_t t1, t2, t3, t4;
    pthread_create(&t1, nullptr, &read, nullptr);
    pthread_create(&t2, nullptr, &read, nullptr);
    pthread_create(&t3, nullptr, &write, nullptr);
    pthread_create(&t4, nullptr, &write, nullptr);

    pthread_join(t1, nullptr);

    return 0;
}
