#pragma once
#include<iostream>
#include<string>
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
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
    //雇员人数
    int num;
    //职工数组指针
    Worker** workerArray;
    //添加职工
    void addE();
};


