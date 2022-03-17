/*
信号量

信号量是一个计数器，用于控制访问有限共享资源的线程数。

相关方法：

// 创建信号量
// pshared：一般取0，表示调用进程的信号量。非0表示该信号量可以共享内存的方式，为多个进程所共享(Linux暂不支持)。
// value：信号量的初始值，可以并发访问的线程数。
int sem_init (sem_t* sem, int pshared, unsigned int value);

int sem_wait (sem_t* sem); // 信号量减1，信号量为0时就会阻塞

int sem_trywait (sem_t* sem); // 信号量减1，信号量为0时返回-1，不阻塞

int sem_timedwait (sem_t* sem, const struct timespec* abs_timeout); // 信号量减1，信号量为0时阻塞，直到abs_timeout超时返回-1

int sem_post (sem_t* sem); // 信号量加1
 */


#include <iostream>
#include <pthread.h>
#include <semaphore.h>

using namespace std;

int ticket_num = 10000000;

sem_t sem;

void *sell_ticket(void *arg){
    while(ticket_num > 0)
    {
        sem_wait(&sem);
        if(ticket_num > 0)
            ticket_num--;
        sem_post(&sem);
    }
}

int main() {
    sem_init(&sem, 0, 1);   //value=1表示最多1个线程同时访问共享资源，与互斥量等价
    pthread_t t1,t2,t3;
    pthread_create(&t1, nullptr, &sell_ticket, nullptr);
    pthread_create(&t2, nullptr, &sell_ticket, nullptr);
    pthread_create(&t3, nullptr, &sell_ticket, nullptr);
    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);
    pthread_join(t3, nullptr);

    cout << "ticket_num --> " << ticket_num << endl;

    return 0;
}
