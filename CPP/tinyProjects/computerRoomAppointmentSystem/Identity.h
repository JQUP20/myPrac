#ifndef __IDENTITY_H__
#define __IDENTITY_H__

#include <iostream>
#include <string>
using namespace std;

class Identity
{
public:

    virtual void operMenu() = 0;

    string m_Name;
    string m_Pwd;
};


#endif
