#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <pthread.h>

/*
  1)C语言中的getpid()函数 (1) getpid() function in C)
When any process is created, it has a unique id which is called its process id. This function returns the process id of the calling function.

创建任何进程时，它都有一个唯一的ID，称为其进程ID。 该函数返回调用函数的进程ID。

Syntax:

句法：

    pid_t getpid();

2)C语言中的getppid()函数 (2) getppid() function in C)
This function returns the process id of the parent function.

该函数返回父函数的进程ID。

Syntax:

句法：

    pid_t getppid();

Note: pid_t is the type of process id, which is an unsigned integer type of data type.

注意： pid_t是进程ID的类型，它是数据类型的无符号整数类型。

 */

/*
 *获取调用线程tid

#include <pthread.h>
pthread_t pthread_self(void);

strerror的函数.

char *strerror(int errnum)  // 返回一个指针错误字符串描述错误编号
0 : Success
1 : Operation not permitted
2 : No such file or directory
3 : No such process
4 : Interrupted system call
5 : Input/output error
6 : No such device or address
7 : Argument list too long
8 : Exec format error
9 : Bad file descriptor
10 : No child processes
 */

/*
 输出:
 main thread, pid ==> 79992id ==> 139877678266176
pthread_join errorchild thread, pid ==> 79992id ==>139877660595968

设置分离属性，detach会失败。。。。。。
 */

using namespace std;

//线程执行函数
void *mythread(void *arg)
{
    cout << "child thread, pid ==> " << getpid() << "id ==>" << pthread_self() << endl;
    sleep(10);
}

int main()
{
    pthread_t thread;
    int ret = pthread_create(&thread, nullptr, mythread, NULL);
    if(ret != 0)
    {
        cout << "pthread_create error" << strerror(ret);
    }

    cout << "main thread, pid ==> " << getpid() << "id ==> " << pthread_self() << endl;

    //
//    pthread_detach(thread);

    //
    ret = pthread_join(thread, nullptr);
    if(ret != 0)
    {
        cout << "pthread_join error" << strerror(ret);
    }

    //目的是为了让子线程能够执行起来
    sleep(2);

    return 0;
}
