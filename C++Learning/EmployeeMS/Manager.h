#pragma once
#include<string>
#include "Worker.h"
using namespace std;

class Manager:public Worker{
    public:
    Manager(string name,int ID,int department);
    virtual void show_info();
    virtual string getdepName();
};