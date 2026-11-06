#include "Boss.h"

Boss::Boss(string name,int ID,int department){
    this->name=name;
    this->ID=ID;
    this->department=department;
}

void Boss::show_info(){
    cout<<"姓名："<<this->name
    <<"\tID："<<this->ID
    <<"\t岗位："<<this->getdepName()
    <<"\t职责：下发任务给经理"<<endl;
}

string Boss::getdepName(){
    return string("老板");
}