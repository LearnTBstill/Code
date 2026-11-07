#pragma once
#include<iostream>
#include<string>
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
#include<fstream>
using namespace std;
#define FILENAME "E_list.txt"

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
    //保存文件
    void fsave();
    //读文件
    void fread();
    //判断文件空
    bool fempty;
    //统计文件中的人数
    int getfnum();
    //初始化职工
    void initE();
    //显示
    void showE();
    //删除
    void deleteE();
    //查找
    int searchE(int ID);
    //修改
    void modify();
};


