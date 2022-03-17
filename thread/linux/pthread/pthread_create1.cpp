/*
 * 创建子线程，传递参数
 */

/*
 pthread_create函数详解

头文件
#include<pthread.h>

函数声明
int  pthread_create(pthread_t *tidp, const  pthread_attr_t *attr,
( void *)(*start_rtn)( void *), void  *arg);

编译链接参数
-lpthread

返回值
若线程创建成功，则返回0。若线程创建失败，则返回出错编号，并且*thread中的内容是未定义的。
返回成功时，由tidp指向的内存单元被设置为新创建线程的线程ID。attr参数用于指定各种不同的线程属性。新创建的线程从start_rtn函数的地址开始运行，该函数只有一个万能 指针参数arg，如果需要向start_rtn函数传递的参数不止一个，那么需要把这些参数放到一个结构中，然后把这个结构的地址作为arg的参数传入。
linux下用C语言开发多线程程序，Linux系统下的多线程遵循POSIX线程接口，称为pthread。
由 restrict 修饰的指针是最初唯一对指针所指向的对象进行存取的方法，仅当第二个指针基于第一个时，才能对对象进行存取。对对象的存取都限定于基于由 restrict 修饰的指针表达式中。 由 restrict 修饰的指针主要用于函数 形参，或指向由 malloc() 分配的内存空间。restrict 数据类型不改变程序的语义。 编译器能通过作出 restrict 修饰的 指针是存取对象的唯一方法的假设，更好地优化某些类型的例程。

参数
第一个参数为指向线程 标识符的 指针。
第二个参数用来设置线程属性。
第三个参数是线程运行函数的起始地址。
最后一个参数是运行函数的参数。

注意事项
因为pthread并非Linux系统的默认库，而是POSIX线程库。在Linux中将其作为一个库来使用，因此加上 -lpthread（或-pthread）以显式链接该库。函数在执行错误时的错误信息将作为返回值返回，并不修改系统全局变量errno，当然也无法使用perror()打印错误信息。
 
 */

/*
 输出:
main thread, pid --> 66083id --> 139940469950272
88Mark
child thread, pid --> 66083id --> 139940452280064
 */

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <pthread.h>
using namespace std;

struct Test{
    int data;
    char name[64];
};

//线程执行函数
void *mythread(void *arg)
{
    struct Test *p =  (struct Test *)arg;

    int n = *(int *)arg;

    //cout << p->data << p->name << endl;
    cout << n << endl;

    cout << "child thread, pid --> " << getpid() << "id --> " << pthread_self() << endl;

    return nullptr;
}

int main()
{
    int n = 99;
    struct Test t;
    memset(&t, 0x00, sizeof(struct Test));
    t.data = 88;
    strcpy(t.name, "Mark");

    //创建子线程
    pthread_t thread;
    //int ret = pthread_create(&thread, nullptr, mythread, &t);
    int ret = pthread_create(&thread, nullptr, mythread, &n);
    if(ret != 0)
    {
        cout << "pthread_create error " << strerror(ret) << endl;
        return -1;
    }

    cout << "main thread, pid --> " << getpid() << "id --> " << pthread_self() << endl;

    sleep(1);

    return 0;
}

