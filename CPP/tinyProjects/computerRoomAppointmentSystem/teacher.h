#ifndef __TEACHER_H__
#define __TEACHER_H__

#include <iostream>
#include <string>
#include <vector>
#include "Identity.h"
#include "orderFile.h"

class Teacher : public Identity
{
public:
    Teacher();

    Teacher(int empId, string name, string pwd);

    virtual void operMenu();

    void showAllOrder();

    void validOrder();

    int m_EmpId;

};



#endif
