#ifndef __ORDER_FILE_H__
#define __ORDER_FILE_H__

#include <iostream>
using namespace std;
#include "globalFile.h"
#include <fstream>
#include <map>
#include <string>

class OrderFile
{
public:
    OrderFile();

    //更新预约记录
    void updateOrder();

    //记录预约条数
    int m_Size;

    //记录所有预约信息的容器  key记录条数  value具体记录键值对信息
    map<int, map<string, string>> m_orderData;
};


#endif
