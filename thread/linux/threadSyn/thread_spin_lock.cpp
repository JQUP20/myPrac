/*
 *自旋锁
自旋锁顾名思义就是一个死循环，不停的轮询，当一个线程未获得自旋锁时，不会像互斥锁一样进入阻塞休眠状态，而是不停的轮询获取锁，如果自旋锁能够很快被释放，那么性能就会很高，如果自旋锁长时间不能够被释放，甚至里面还有大量的IO阻塞，就会导致其他获取锁的线程一直空轮询，导致CPU使用率达到100%，特别CPU时间。

相关方法：

int pthread_spin_init(pthread_spinlock_t *lock, int pshared); // 创建自旋锁

int pthread_spin_lock(pthread_spinlock_t *lock); // 加锁，阻塞
int pthread_spin_trylock(pthread_spinlock_t *lock); // 尝试加锁，非阻塞
int pthread_spin_unlock(pthread_spinlock_t *lock); // 解锁
*/


#include <iostream>
#include <pthread.h>

using namespace std;

 pthread_spinlock_t spinlock;

int ticket_num = 10000000;

void *sell_ticket(void *arg){
    while(ticket_num > 0)
    {
        pthread_spin_lock(&spinlock);
        if(ticket_num > 0)
            ticket_num--;
        pthread_spin_unlock(&spinlock);
    }
}

int main() {
    pthread_spin_init(&spinlock, 0);
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
