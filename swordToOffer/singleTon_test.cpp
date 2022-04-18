#include <iostream>
#include "Singleton.hpp"
using namespace std;

int main()
{
    HungrySingleton *p1 = HungrySingleton::getInstance();
    HungrySingleton *p2 = HungrySingleton::getInstance();

    if(p1 == p2)
        cout << "same" << endl;

    return 0;
}

