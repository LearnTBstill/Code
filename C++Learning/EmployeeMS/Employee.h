#pragma once
#include<string>
#include <iostream>
#include "EmployeeManage.h"
using namespace std;

class Employee:public Worker{    
    public:
    Employee(string name,int ID,int department);
    //显示雇员个人信息
    virtual void show_info();
    //显示雇员岗位 
    virtual string getdepName();
};