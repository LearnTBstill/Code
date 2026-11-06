#pragma once
#include<string>
#include <iostream>
using namespace std;

class Worker{
    public:
    //显示个人信息
    virtual void show_info()=0;
    //显示岗位
    virtual string getdepName()=0;

    //职工编号
    int ID;
    //职工姓名
    string name;
    //职工所在部门编号
    int department;
};