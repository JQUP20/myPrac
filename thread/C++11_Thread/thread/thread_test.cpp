/*
 * 与 C++11 多线程相关的头文件地方

C++11 新标准中引入了四个头文件来支持多线程编程，他们分别是<atomic> ,<thread>,<mutex>,<condition_variable>和<future>。

<atomic>：该头文主要声明了两个类, std::atomic 和 std::atomic_flag，另外还声明了一套 C 风格的原子类型和与 C 兼容的原子操作的函数。
<thread>：该头文件主要声明了 std::thread 类，另外 std::this_thread 命名空间也在该头文件中。
<mutex>：该头文件主要声明了与互斥量(mutex)相关的类，包括 std::mutex 系列类，std::lock_guard, std::unique_lock, 以及其他的类型和函数。
<condition_variable>：该头文件主要声明了与条件变量相关的类，包括 std::condition_variable 和 std::condition_variable_any。
<future>：该头文件主要声明了 std::promise, std::package_task 两个 Provider 类，以及 std::future 和 std::shared_future 两个 Future 类，另外还有一些与之相关的类型和函数，std::async() 函数就声明在此头文件中。

*/

#include <iostream>
#include <thread>

using namespace std;

void th_func()
{
    cout << "hello thread" << endl;
}

void test01()
{
    thread t(th_func);
    t.join();
}

// test02
void thread_func1()
{
    for(int i = 0; i != 10; ++i)
        cout << "thread 1 print " << i << endl;
}

void thread_func2(int n)
{
    cout << "thread 2 print " << n << endl;
}

void test02()
{
    thread t1(thread_func1);
    thread t2(thread_func2, 111);

    cout << "main, func1, func2 new execute concurrently...\n" << endl;

    t1.join();
    t2.join();

}

//test03
#include <chrono>

void pause_thread(int n)
{
    this_thread::sleep_for(chrono::seconds(n));
    cout << "pause of" << n << "seconds ended" << endl;
}

void test03()
{
    thread threads[5];

    cout << "Spawning 5 threads...\n" ;
    for(int i = 0; i < 5; ++i)
        threads[i] = thread(pause_thread, i + 1);

    cout << "Done spawning threads. Now waiting for them to join:" << endl;
    for(int i = 0; i < 5; i++)
        threads[i].join();

    cout << "All threads joined!" << endl;
}

//test04 构造函数
void func1(int n)
{
    cout << "Thread " << n << " executing\n";
    n += 10;
    this_thread::sleep_for(chrono::milliseconds(10));
}

void func2(int& n)
{
    cout << "Thread " << n << "executing" << endl;
    n += 20;
    this_thread::sleep_for(chrono::milliseconds(10));
}

void test04()
{
    int n = 0;
    thread t1;              //t1不是一个thread  
    thread t2(func1, n + 1);    //按照值传递
    t2.join();
    cout << "n = " << n << endl;
    n = 10;
    thread t3(func2, ref(n));   //引用
    thread t4(move(t3));         //t4执行t3，t3不是thread  
    t4.join();
    cout << "n = " << n << endl;
}

//test05 异步
void show()
{
    cout << "hello cplusplus!" << endl;
}

void test05()
{
    //栈上
    thread t1(show);
    thread t2(show);
    thread t3(show);

    cout << endl;
    //线程数组
    thread th[3]{ thread(show), thread(show), thread(show) };

    cout << endl;
    //堆上
    thread *ptr1(new thread(show));
    thread *ptr2(new thread(show));
    thread *ptr3(new thread(show));

    cout << endl;

    //线程指针数组
    thread *pth (new thread[3]{ thread(show), thread(show), thread(show)});
}

//test06 多线程传递参数
#include <unistd.h>
void show1(const char *str, const int id)
{
    cout << "线程 " << id + 1 << " : " << str << endl;
}

void test06()
{
   thread t1(show1, "hello cplusplus!", 0);
   thread t2(show1, "你好，C++！", 1);
   thread t3(show1, "hello!", 2);
  // sleep(2);

   t1.join();
   t2.join();
   t3.join();
}

//test07 join detach
//join 是让当前主线程等待所有的子线程执行完，才能退出。
void test07_1()
{
    array<thread, 3> threads = { thread(show), thread(show), thread(show) };

    for(int i = 0; i < 3; i++)
    {
        cout << threads[i].joinable() << endl;
        threads[i].join();
    }
}

void test07_2()
{
    thread th(show);
    th.detach();            //脱离主线程的绑定，主线程挂了，子线程不报错，子线程执行完自动退出。
    //detach以后，子线程会成为孤儿线程，线程之间将无法通信。
    cout << th.joinable() << endl;
}

//test08 获取CPU核心个数
void test08()
{
    auto n = thread::hardware_concurrency();
    cout << n << endl;
}

//test09 C++原子变量和线程安全
//
const int N = 10000000;
int num = 0;
void run()
{
    for(int i = 0; i < N; i++)
    {
        num++;
    }
}

//
#include <mutex>
mutex m;
void run1()
{
    for(int i = 0; i < N; i++)
    {
        m.lock();
        num++;
        m.unlock();
    }
}

//
#include <atomic>
atomic_int num1{ 0 };
void run2()
{
    for(int i = 0; i < N; i++)
    {
        num1++;
    }
}

/*
 * 发现结果并不是我们预计的200000000，这是由于线程之间发生冲突，从而导致结果不正确。
 */
void test09_1()
{
    clock_t start = clock();

    //thread t1(run);
    //thread t2(run);
    
    thread t1(run1);
    thread t2(run1);

    t1.join();
    t2.join();

    clock_t end = clock();
    cout << "num=" << num << ",用时" << end - start << "ms" << endl;
}

/*
 * 不难发现，通过原子变量后运算结果正确，计算速度也很理想。
*/


//test10() lambda和多线程
void test10()
{
    auto fun = [](const char *str) { cout << str << endl; };
    thread t1(fun, "hello world!");
    thread t2(fun, "hello beijing!");
    t1.join();
    t2.join();
}

//test11() 时间等待相关问题
void test11()
{
    thread th1([]()
    {
        this_thread::sleep_for(chrono::seconds(3));
        this_thread::yield();
        cout << this_thread::get_id() << endl;
    });
}

//test12() 线程功能拓展
class MyThread : public thread
{
public:
    MyThread() : thread()
    {
    }

    template<typename T, typename...Args>
    MyThread(T&&func, Args&&...args) : thread(forward<T>(func), forward<Args>(args)...)
    {
    }

    void showcmd(const char *str)
    {
        system(str);
    }
};

void test12()
{
    MyThread th1([]()
    {
        cout << "helllo" << endl;
    });

    th1.showcmd("calc");

    MyThread th2([](const char* str)        
    {   
        cout << "hello" << str << endl;
    }, "this is MyThread");

    th2.showcmd("notepad");
}

//test13() 多线程可变参数
#include <cstdarg>
int show3(const char *fun, ...)
{
    va_list ap;
    va_start(ap, fun);
    vprintf(fun, ap);
    va_end(ap);
}

void test13()
{
    thread t1(show3, "%s     %d      %c      %f", "hello world", 100, 'A', 3.14159);
    t1.join();
}

//test14() 线程交换
void test14()
{
    thread t1([]()
    {
        cout << "thread1" << endl;
    });
    thread t2([]()
    {
        cout << "thread2" << endl;
    });

    cout << "thread1' id is " << t1.get_id() << endl;
    cout << "thread2' id is " << t2.get_id() << endl;

    cout << "swap after:" << endl;
    swap(t1, t2);
    cout << "thread1' id is " << t1.get_id() << endl;
    cout << "thread2' id is " << t2.get_id() << endl;
}

//test15() 线程移动
//线程t2可以通过 move 移动 t1 来获取 t1 的全部属性，而 t1 却销毁了。
void test15()
{
    thread t1([]()
    {
        cout << "thread1" << endl;
    });
    cout << "thread1' id is " << t1.get_id() << endl;
    thread t2 = move(t1);
    cout << "thread2' id is " << t2.get_id() << endl;
    t2.join();
}

int main()
{
 //   test01();
 //   test02()
 //   test03();
//    test04();
 //   test05();
 //   test06();
 //   test07_2();
 //   test08();
 //    test09_1();
 //   test10();
 //   test11();
 //   test12();
 //   test13();
 //   test14();
    test15();
    return 0;
}

























































































