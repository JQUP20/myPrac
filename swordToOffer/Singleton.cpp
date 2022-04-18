#ifndef SINGLETON_H__
#define SINGLETON_H__

#include <iostream>
#include <pthread.h>
/*
 * 经典的线程安全懒汉模式
 */
class LazySingleton_1{
private:
    static LazySingleton_1 *p;
    static pthread_mutex_t lock;

    LazySingleton(){
        pthread_mutex_init(&lock, nullptr);
    }
    ~LazySingleton(){}

public:
    static LazySingleton_1 getInstance();

};

pthread_mutex_t LazySingleton_1::lock;

LazySingleton_1* LazySingleton_1::p = nullptr;
LazySingleton_1* LazySingleton_1::getInstance(){
    if(nullptr == p){
        pthread_mutex_lock(&lock);
        if(nullptr == p){
            p = new LazySingleton_1;
        }
        pthread_mutex_unlock(&lock);
    }
    return p;
}


class LazySingleton{
private:
    LazySingleton(){}
    ~LazySingleton(){}

public:
    static LazySingleton* getInstance();
};

LazySingleton* LazySingleton::getInstance(){
    static LazySingleton obj;
    return &obj;
}

class HungrySingleton{
private:
    static HungrySingleton* p;
    HungrySingleton() {}
    ~HungrySingleton() {}

public:
    static HungrySingleton* getInstance();
};

HungrySingleton* HungrySingleton::p = new HungrySingleton();
HungrySingleton* HungrySingleton::getInstance(){
    return p;
}


#endif 

