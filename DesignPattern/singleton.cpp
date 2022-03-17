#include <iostream>

/*
 * 单例模式
 * 单例模式作为最常用的设计模式之一，保证一个类仅有一个实例，并提供一个访问它的全局访问点，该实例被所有程序模块共享。

实现思路：私有化它的构造函数，以防止外界创建单例类的对象；使用类的私有静态指针变量指向类的唯一实例，并用一个公有的静态方法获取该实例。

单例模式有两种实现方法，分别是懒汉和饿汉模式。顾名思义，懒汉模式，即非常懒，不用的时候不去初始化，所以在第一次被使用时才进行初始化；饿汉模式，即迫不及待，在程序运行时立即初始化。
*/


//经典的线程安全懒汉模式,使用双检测锁模式。

/*
 * 为什么要用双检测，只检测一次不行吗？

如果只检测一次，在每次调用获取实例的方法时，都需要加锁，这将严重影响程序性能。双层检测可以有效避免这种情况，仅在第一次创建单例的时候加锁，其他时候都不再符合NULL == p的情况，直接返回已创建好的实例。
 */

class SingleTon{
public:
    //私有静态指针变量指向唯一实例
    static single *p;

    //静态锁，是由于静态函数只能访问静态成员
    static pthread_mutex_t lock;

    //私有化构造函数
    SingleTon()
    {
        pthread_mutex_init(&lock, nullptr);
    }

    ~SingleTon();

public:
    //公有静态方法获取实例
    static SingleTon* getInstance();
};


/*
 * //双重检查，防止多个线程同时进入第一层检查(因单例模式只允许存在一个对象，故在创建对象之前无引用指向对象，所有线程均可进入第一层检查)
   //当某一线程获得锁创建一个Singleton对象时,即已有引用指向对象，singleton不为空，从而保证只会创建一个对象
   //假设没有第二层检查，那么第一个线程创建完对象释放锁后，后面进入对象也会创建对象，会产生多个对象
 */
pthread_mutex_t SingleTon::lock;

SingleTon* SingleTon::p = nullptr;
SingleTon* SingleTon::getInstance()
{
    if(nullptr == p)                //第一层检查，检查是否有引用指向对象，高并发情况下会有多个线程同时进入
    {
        pthread_mutex_lock(&lock);  //第一层锁，保证只有一个线程进入
        if(nullptr == p)
        {
            p = new SingleTon;
        }
        pthread_mutex_unlock(&lock);
    }
    return p;
}



/*
 * 局部静态变量之线程安全懒汉模式
前面的双检测锁模式，写起来不太优雅，《Effective C++》（Item 04）中的提出另一种更优雅的单例模式实现，使用函数内的局部静态对象，这种方法不用加锁和解锁操作。
*/

class SingleTon{
private:
    SingleTon() {}
    ~SingleTon() {}

public:
    static single* getInstance();
};

SingleTon* SingleTon::getInstance()
{
    static SingleTon obj;
    return &obj;
}
/*
 * 这时候有人说了，这种方法不加锁会不会造成线程安全问题？

其实，C++0X以后，要求编译器保证内部静态变量的线程安全性，故C++0x之后该实现是线程安全的，C++0x之前仍需加锁，其中C++0x是C++11标准成为正式标准之前的草案临时名字。

所以，如果使用C++11之前的标准，还是需要加锁，这里同样给出加锁的版本。
*/
class SingleTon{
private:
    static pthread_mutex_t lock;
    SingleTon() {
        pthread_mutex_init(&lock, nullptr);
    }
    ~SingleTon() {}

public:
    static single* getInstance();
};

pthread_mutex_t SingleTon::lock;

SingleTon* SingleTon::getInstance()
{
    pthread_mutex_lock(&lock);
    static SingleTon obj;
    pthread_mutex_unlock(&lock);
    return &obj;
}

/*
 * 饿汉模式
饿汉模式不需要用锁，就可以实现线程安全。原因在于，在程序运行时就定义了对象，并对其初始化。之后，不管哪个线程调用成员函数getinstance()，都只不过是返回一个对象的指针而已。所以是线程安全的，不需要在获取实例的成员函数中加锁。
*/
class SingleTon{
private:
    static SingleTon* p;
    SingleTon() {}
    ~SingleTon() {}

public:
    static single* getInstance();
};

SingleTon* SingleTon::p = new single();
Single* Single::getInstance(){
    return p;
}

int main()
{
    SingleTon *p1 = SingleTon::getInstance();
    SingleTon *p2 = SingleTon::getInstance();

    if(p1 == p2)
        cout << "same" <<endl;

    return 0;
}




