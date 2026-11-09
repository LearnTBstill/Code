#include "EmployeeManage.h"
#include<iostream>
using namespace std;

//员工管理的构造函数
EmployeeManage::EmployeeManage(){
    //三种情况初始化
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open()){//文件不存在
        this->num=0; 
        this->workerArray=NULL;
        this->fempty=true;
        ifs.close();
        return;
    }
    char ch;
    ifs>>ch;
    if(ifs.eof()){//文件为空
        this->num=0; 
        this->workerArray=NULL;
        this->fempty=true;
        ifs.close();
        return;
    }
    //文件存在并且非空
    int num=this->getfnum();
    cout<<"职工人数为"<<num<<endl; 
    this->num=num;
    //如果关闭了之后再打开文件，就需要在构造函数里面重新申请堆空间
    //这就是为什么你在"添加"里面new过了还要在构造函数中申请
    this->workerArray=new Worker*[this->num];//别忘了堆上创建数组
    this->initE();
    ifs.close();

    // //test
    // for(int i=0;i<this->num;i++)
    // {
    //     cout<<"姓名："<<this->workerArray[i]->name
    //     <<"\tID："<<this->workerArray[i]->ID
    //     <<"\t岗位："<<this->workerArray[i]->department<<endl;
    // }
}

//员工管理的析构函数
EmployeeManage::~EmployeeManage(){
    if(this->workerArray!=NULL){
        for(int i=0;i<this->num;i++){
            delete(this->workerArray[i]);
            this->workerArray[i]=NULL;
        }
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
    system("cls");
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
                    cout<<"输入错误,重新输入"<<endl;
                    j--;//让用户重新输入
                    continue;
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
        this->fempty=false;
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
    for(int i=0;i<this->num;i++){
        ofs<<this->workerArray[i]->name<<"   "
        <<this->workerArray[i]->ID<<"   "
        <<this->workerArray[i]->department<<"   "<<endl;
    }
    ofs.close();   
}

//统计文件中的人数
int EmployeeManage::getfnum(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int ID;string name;int department;
    int num=0;
    while(ifs>>name&&ifs>>ID&&ifs>>department){
        num++;
    }   
    return num;
}

//初始化职工
void EmployeeManage::initE(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int ID;string name;int d;
    int i=0;
    while(ifs>>name>>ID>>d){
        Worker* w=NULL;
        if(d==1){
            w=new Employee(name,ID,d);
        }
        else if(d==2){
            w=new Manager(name,ID,d);
        }
        else{
            w=new Boss(name,ID,d);
        }
        this->workerArray[i++]=w;
    }
    this->fempty=false;
    ifs.close();
}

//显示
void EmployeeManage::showE(){   
    if(this->fempty){
        cout<<"文件为空或不存在！"<<endl;
        return;
    }
    else{
        for(int i=0;i<this->num;i++){
            this->workerArray[i]->show_info();
        }
    }
    system("pause");
    system("cls"); 
}

//删除
void EmployeeManage::deleteE(){
    if(this->fempty){
        cout<<"文件不存在或为空"<<endl;
    }
    else{
        cout<<"请输入ID"<<endl;
        int id=0;
        cin>>id;
        int res=searchE(id);
        if(res==-1){
            cout<<"未找到"<<endl;
        }
        else{
            Worker* temp=this->workerArray[res];
            delete(temp);
            this->workerArray[res]=NULL;//注意不是给temp置NULL
            for(;res<this->num-1;res++){
                this->workerArray[res]=this->workerArray[res+1];
            }
            this->num--;
            //别忘了同步到文件中
            this->fsave();
            cout<<"删除成功"<<endl;
        }
    }
    system("pause");
    system("cls");
}

//查找
int EmployeeManage::searchE(int ID){
    int index=-1;
    for(int i=0;i<this->num;i++){
        if(this->workerArray[i]->ID==ID){
            index=i;
            break;
        }
    }
    return index;
}

//修改
void EmployeeManage::modify(){
    if(this->fempty){
        cout<<"文件不存在或为空"<<endl;
    }
    else{
        cout<<"请输入修改职工的ID："<<endl;
        int id=0;
        cin>>id;
        int res=this->searchE(id);
        if(res==-1){
            cout<<"未找到"<<endl;
        }
        else{
            delete(this->workerArray[res]);
            cout<<"已找到"<<id<<"号职工"<<endl;
            int nID;string nname;int nd;
            cout<<"请输入新的ID："<<endl;
            cin>>nID;
            cout<<"请输入新的姓名："<<endl;
            cin>>nname;
            cout<<"请输入新的岗位："<<endl;
            cout<<"1.员工"<<endl<<"2.经理"<<endl<<"3.老板"<<endl;
            cin>>nd;
            Worker* w=NULL;
            switch(nd){
                case 1:{
                    w=new Employee(nname,nID,nd);
                    break;
                }
                case 2:{
                    w=new Manager(nname,nID,nd);
                    break;
                }
                case 3:{
                    w=new Boss(nname,nID,nd);
                    break;
                }
                default:{
                    cout<<"输入有误"<<endl;
                    break;
                }
            }
            this->workerArray[res]=w;
            cout<<"修改成功"<<endl;
            this->fsave();
        }
        system("pause");
        system("cls");
    }
}

//按照编号或者姓名查找
void EmployeeManage::FindE(){
    if(this->fempty){
        cout<<"文件为空或者不存在"<<endl;
    }
    else{
        cout<<"请输入查找方式："<<endl;
        cout<<"1.按照ID查询"<<endl;
        cout<<"2.按照姓名查询"<<endl;
        int manner;
        cin>>manner;
        switch(manner){
            case 1:{
                cout<<"请输入ID："<<endl;
                int id=0;
                cin>>id;
                int res=this->searchE(id);
                if(res==-1){
                    cout<<"查无此人"<<endl;
                }
                else{
                    this->workerArray[res]->show_info();
                }
                break;
            }
            case 2:{
                string name;
                int flag=0;
                cout<<"请输入姓名："<<endl;
                cin>>name;
                for(int i=0;i<this->num;i++){
                    if(this->workerArray[i]->name==name){
                        this->workerArray[i]->show_info();
                        flag=1;
                    }
                }
                if(flag==0){
                    cout<<"查找失败"<<endl;
                }
                break;
            }
            default:{
                cout<<"输入有误"<<endl;
                break;
            }
        } 
    }
    system("pause");
    system("cls");
}

//按照编号排序
void EmployeeManage::Bubblesort(){
    if(this->fempty){
        cout<<"文件空或者不存在"<<endl;
        system("pause");
        system("cls");
    }
    else{
        cout<<"请选择排序方式："<<endl;
        cout<<"1.升序"<<endl;
        cout<<"2.降序"<<endl;
        int n=0;
        cin>>n;
        for(int i=0;i<this->num;i++){
            int swap=0;
            for(int j=this->num-1;j>i;j--){
                if(n==1){
                    if(this->workerArray[j]->ID<this->workerArray[j-1]->ID){
                        Worker* temp=0;
                        temp=this->workerArray[j];
                        this->workerArray[j]=this->workerArray[j-1];
                        this->workerArray[j-1]=temp;
                        swap=1;
                    }
                }
                else if(n==2){
                    if(this->workerArray[j]->ID>this->workerArray[j-1]->ID){
                        Worker* temp=0;
                        temp=this->workerArray[j];
                        this->workerArray[j]=this->workerArray[j-1];
                        this->workerArray[j-1]=temp;
                        swap=1;
                    }
                }
            }
            if(swap==0){
                break;
            }
        }
        this->fsave();
        this->showE();
    }
}

//清空
void EmployeeManage::clear(){
    cout<<"确认清空请输入'确认'"<<endl;
    string temp;
    cin>>temp;
    if(temp=="确认"){
        ofstream ofs(FILENAME,ios::trunc);
        ofs.close();
        //就算析构函数有也要在这里写,怕用户清空之后继续添加什么的
        for(int i=0;i<this->num;i++){
            delete(this->workerArray[i]);
            this->workerArray[i]==NULL;
        }
        delete[] this->workerArray;
        this->workerArray=NULL;//忘记置NULL
        this->num=0;
        this->fempty=true;
        cout<<"清空成功"<<endl;
    }
    system("pause");
    system("cls");
}
