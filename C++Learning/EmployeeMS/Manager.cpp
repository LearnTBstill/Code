#include "Manager.h"

Manager::Manager(string name,int ID,int department){
    this->name=name;
    this->ID=ID;
    this->department=department;
}

void Manager::show_info(){
    cout<<"姓名："<<this->name
    <<"\tID："<<this->ID
    <<"\t岗位："<<this->getdepName()
    <<"\t职责：完成老板任务，并下发"<<endl;
}

string Manager::getdepName(){
    return string("经理");
}