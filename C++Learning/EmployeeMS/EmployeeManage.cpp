#include "EmployeeManage.h"
#include<iostream>
using namespace std;

//员工管理的构造函数
EmployeeManage::EmployeeManage(){
    this->num=0; 
    this->workerArray=NULL;
}

//员工管理的析构函数
EmployeeManage::~EmployeeManage(){
    if(this->workerArray!=NULL){
        delete[] this->workerArray;
        this->workerArray=NULL;
    }
}

//展示菜单
void EmployeeManage::show_menu(){
    cout << "**********************************" << endl;
    cout << "*******欢迎使用职工管理系统*******" << endl;
    cout << "********* 0.退出管理程序 *********" << endl;
    cout << "********* 1.增加职工信息 *********" << endl;
    cout << "********* 2.显示职工信息 *********" << endl;
    cout << "********* 3.删除离职职工 *********" << endl;
    cout << "********* 4.修改职工信息 *********" << endl;
    cout << "********* 5.查找职工信息 *********" << endl;
    cout << "********* 6.按照编号排序 *********" << endl;
    cout << "********* 7.清空所有文档 *********" << endl;
    cout << "**********************************" << endl<<endl;
}

//退出
void EmployeeManage::exit_system(){
    cout<<"欢迎下次使用"<<endl;
    system("pause");
    exit(0);//推出并返回0
}

//添加
void EmployeeManage::addE(){
    cout<<"请输入添加职工数量："<<endl;
    int i=0;
    cin>>i;
    if(i>0){
        //计算新数组人数
        int newnum=this->num+i;
        Worker** newarray=new Worker*[newnum];
        if(this->workerArray!=NULL){
            for(int j=0;j<this->num;j++){
                newarray[j]=this->workerArray[j];
            }
        }
        //添加
        for(int j=0;j<i;j++){
            int ID;
            string name;
            int d;
            cout<<"请输入第"<<j+1<<"个职工的ID："<<endl;
            cin>>ID;
            cout<<"请输入第"<<j+1<<"个职工的name："<<endl;
            cin>>name;
            cout<<"请选择该职工岗位："<<endl<<"1.员工"<<endl<<"2.经理"<<endl<<"3.老板"<<endl;
            cin>>d;
            Worker* worker=NULL;
            switch(d){
                case 1:{
                    worker=new Employee(name,ID,d);
                    break;
                }
                case 2:{
                    worker=new Manager(name,ID,d);
                    break;
                }
                case 3:{
                    worker=new Boss(name,ID,d);
                    break;
                }
                default:{
                    cout<<"输入错误"<<endl;
                    break;
                }
            }
            newarray[this->num+j]=worker;
            // delete(worker);//这里不能delete,不然刚存进去的worker立马被删除了,是会多占用点内存但是是必要开销
        }
        //释放原有空间
        delete[] this->workerArray;
        this->workerArray=newarray;
        this->num=newnum;
        cout<<"成功添加"<<i<<"人"<<endl;
        //保存
        this->fsave();
    }
    else{
        cout<<"输入有误"<<endl;
    }
    //清屏
    system("pause");
    system("cls");
}

//保存文件
void EmployeeManage::fsave(){
    ofstream ofs;
    ofs.open(FILENAME,ios::out);
    for(int i;i<this->num;i++){
        ofs<<this->workerArray[i]->name<<"   "
        <<this->workerArray[i]->ID<<"   "
        <<this->workerArray[i]->department<<"   "<<endl;
    }
    ofs.close();   
}