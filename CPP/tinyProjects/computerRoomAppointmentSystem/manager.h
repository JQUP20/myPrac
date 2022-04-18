#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include "Identity.h"
#include "globalFile.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include <algorithm>
#include "computerRoom.h"

class Manager : public Identity
{
public:
    Manager();

    Manager(string name, string pwd);

    virtual void operMenu();

    //添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void cleanFile();

	//初始化容器
	void initVector();

	//检测重复 参数1 检测学号/职工号  参数2  检测类型
	bool checkRepeat(int id , int type);

	//学生容器
	vector<Student>vStu;

	//教师容器
	vector<Teacher>vTea;

	//机房信息容器
	vector<ComputerRoom>vCom;
};


#endif
