#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "computerRoom.h"
#include <fstream>
#include "globalFile.h"
#include "orderFile.h"
#include "Identity.h"

class Student : public Identity
{
public:
    Student();
    Student(int id, string name, string pwd);

    //
    virtual void operMenu();

    //申请预约
    void applyOrder();

    //查看自身预约
    void showMyOrder();

    //查看所有预约
    void showAllOrder();

    //取消预约
    void cancelOrder();

    int m_Id;
    vector<ComputerRoom> vCom;
};


#endif
