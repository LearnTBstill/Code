#include "Employee.h"

Employee::Employee(string name,int ID,int department){
    this->name=name;
    this->ID=ID;
    this->department=department;
}

void Employee::show_info(){
    cout<<"名字为："<<this->name
    <<"\tID为："<<this->ID
    <<"\t岗位为："<<this->getdepName()
    <<"\t岗位职责：完成经理交给的任务"<<endl;
}

string Employee::getdepName(){
    return "员工";
}