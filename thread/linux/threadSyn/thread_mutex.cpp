/*
 * 互斥锁
互斥锁本质就是一个特殊的全局变量，拥有lock和unlock两种状态，unlock的互斥锁可以由某个线程获得，当互斥锁由某个线程持有后，这个互斥锁会锁上变成lock状态，此后只有该线程有权力打开该锁，其他想要获得该互斥锁的线程都会阻塞，直到互斥锁被解锁。

互斥锁的类型：

普通锁（PTHREAD_MUTEX_NORMAL）：互斥锁默认类型。当一个线程对一个普通锁加锁以后，其余请求该锁的线程将形成一个 等待队列，并在该锁解锁后按照优先级获得它，这种锁类型保证了资源分配的公平性。一个 线程如果对一个已经加锁的普通锁再次加锁，将引发死锁；对一个已经被其他线程加锁的普 通锁解锁，或者对一个已经解锁的普通锁再次解锁，将导致不可预期的后果。

检错锁（PTHREAD_MUTEX_ERRORCHECK）：一个线程如果对一个已经加锁的检错锁再次加锁，则加锁操作返回EDEADLK；对一个已 经被其他线程加锁的检错锁解锁或者对一个已经解锁的检错锁再次解锁，则解锁操作返回 EPERM。

嵌套锁（PTHREAD_MUTEX_RECURSIVE）：该锁允许一个线程在释放锁之前多次对它加锁而不发生死锁；其他线程要获得这个锁，则当前锁的拥有者必须执行多次解锁操作；对一个已经被其他线程加锁的嵌套锁解锁，或者对一个已经解锁的嵌套锁再次解锁，则解锁操作返回EPERM。

默认锁（PTHREAD_MUTEX_ DEFAULT）：一个线程如果对一个已经加锁的默认锁再次加锁，或者虽一个已经被其他线程加锁的默 认锁解锁，或者对一个解锁的默认锁解锁，将导致不可预期的后果；这种锁实现的时候可能 被映射成上述三种锁之一。a



// 静态方式创建互斥锁
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// 动态方式创建互斥锁，其中参数mutexattr用于指定互斥锁的类型，具体类型见上面四种，如果为NULL，就是普通锁。
int pthread_mutex_init (pthread_mutex_t* mutex,const pthread_mutexattr_t* mutexattr);

int pthread_mutex_lock(pthread_mutex_t *mutex); // 加锁，阻塞
int pthread_mutex_trylock(pthread_mutex_t *mutex); // 尝试加锁，非阻塞
int pthread_mutex_unlock(pthread_mutex_t *mutex); // 解锁

*/


#include <iostream>
#include <pthread.h>

using namespace std;

int ticket_num = 10000000;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *sell_ticket(void *arg){
    while(ticket_num > 0)
    {
        pthread_mutex_lock(&mutex);
        if(ticket_num > 0)
        {
            ticket_num--;
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
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
