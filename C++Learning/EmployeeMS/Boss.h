#pragma once
#include<string>
#include "Worker.h"
using namespace std;

class Boss:public Worker{
    public:
    Boss(string name,int ID,int department);
    virtual void show_info();
    virtual string getdepName();
};