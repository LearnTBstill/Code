#include "Employee.h"

Employee::Employee(string name,int ID,int department){
    this->name=name;
    this->ID=ID;
    this->department=department;
}

void Employee::show_info(){//\t水平制表符
    cout<<"姓名："<<this->name
    <<"\tID："<<this->ID
    <<"\t岗位："<<this->getdepName()
    <<"\t职责：完成经理交给的任务"<<endl;
}

string Employee::getdepName(){
    return string("员工");//直接写的话是const char*，不过编译器可以帮你自动转为string
}