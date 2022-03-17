#include <iostream>
#include <cstring>
#include <unistd.h>
#include <pthread.h>

/*
 *
main thread, pid --> 78527 id --> 139984484886336
child thread, pid --> 78527id --> 139984467216128
child exit status --> 99 Mark 0x6021e0
 */

using namespace std

struct Test
{
    int data;
    char name[64];
};

int g_var = 9;
struct Test t;

void *mythread(void *arg)
{
    cout << "child thread, pid --> " << getpid() << "id --> " << pthread_self() << endl;

    memset(&t, 0x00, sizeof(t));
    t.data = 99;
    strcpy(t.name, "Mark");
    pthread_exit(&t);
}

int main()
{
    pthread_t thread;
    int ret = pthread_create(&thread, nullptr, mythread, nullptr);
    
    if(ret != 0)
    {
        cout << "pthread_create error," << strerror(ret) << endl;
        return -1;
    }
    cout << "main thread, pid --> " << getpid() << " id --> " << pthread_self() << endl;

    //
    void *p = nullptr;
    pthread_join(thread, &p);

    struct Test *pt = (struct Test *)p;
    cout << "child exit status --> " << pt->data << " " << pt->name << " " << p << endl;  
    return 0;
}
