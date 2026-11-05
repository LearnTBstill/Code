#pragma once
#include<iostream>
#include<string>
using namespace std;

class EmployeeManage{
    public:
    //构造函数
    EmployeeManage();
    //析构函数
    ~EmployeeManage();
    //菜单
    void show_menu();
    //退出
    void exit_system(); 
};

class Worker{
    public:
    //显示个人信息
    virtual void show_info()=0;
    //显示岗位
    virtual string show_depName()=0;

    //职工编号
    int ID;
    //职工姓名
    string name;
    //职工所在部门编号
    int department;
};

