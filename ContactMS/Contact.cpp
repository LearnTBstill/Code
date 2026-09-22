#include<iostream>
#include<string>
using namespace std;

typedef struct Person{
    string name;
    int sex;
    int age;
    string phnum;
    string address;
}Person;

#define MAX 1000//宏定义一个MAX方便后期修改人数上限 
typedef struct ContactBooks{
    Person person[MAX];
    int size;
}Contact;

void add(Contact* con){
    if(con->size>=MAX){
        cout<<"通讯录已满，无法添加"<<endl;
        return;
    }
    else{
        //姓名
        string name;//先创建一个变量再赋值是为了方便检验
        cout<<"请输入姓名:"<<endl;
        cin>>name;
        con->person[con->size].name=name;//con->person[con->size]取出来的是实体而非指针所以用"."
        //性别
        int sex;
        cout<<"请输入性别:"<<endl<<"1---男性"<<endl<<"2---女性"<<endl;
        while(true){
            cin>>sex;
            if(sex==1||sex==2){
                con->person[con->size].sex=sex;
                break;
            }
            else{
                cout<<"输入错误，请重新输入:"<<endl;
            }
        }
        //年龄
        int age=0;
        cout<<"请输入年龄:"<<endl;
        cin>>age;
        con->person[con->size].age=age;
        //电话
        string phnum;
        cout<<"请输入电话:"<<endl;
        while(true){
            cin>>phnum;
            if(phnum.size()!=11){
                cout<<"输入长度有误，请重新输入:"<<endl;
                continue;
            }
            else{
                con->person[con->size].phnum=phnum;
                break;
            }
        }
        //地址
        string address;
        cout<<"请输入地址:"<<endl;
        cin>>address;
        con->person[con->size++].address=address;
        cout<<"添加成功"<<endl;
        system("pause");
        system("cls");//清屏
    }
}

void show(Contact *con){//用地址传防止每次调用都拷贝整个数组
    if(con->size==0){
        cout<<"无联系人"<<endl;
        system("pause");
        system("cls");
        return;
    }
    else{
        for(int i=0;i<con->size;i++){    
            cout<<"姓名:"<<con->person[i].name<<"\t";//水平制表符，空出8个位置，跟TAB一样 
            cout<<"性别:"<<(con->person[i].sex==1?"男":"女")<<"\t";                                           
            cout<<"年龄:"<<con->person[i].age<<"\t"; 
            cout<<"电话:"<<con->person[i].phnum<<"\t";
            cout<<"地址:"<<con->person[i].address<<endl; 
        }
    }
}

int find(Contact *con,string name){
    for(int i=0;i<con->size;i++){
        if(con->person[i].name==name){
            return i;
        }
    }
    return -1;
}

void scan(Contact *con,string name){
    int i=find(con,name);//本来传进来就是地址了，就不用再&传入find
    if(i==-1){
        cout<<"查无此人"<<endl;
    }
    else{
        cout<<"姓名:"<<con->person[i].name<<"\t";
        cout<<"性别:"<<(con->person[i].sex==1?"男":"女")<<"\t";                                           
        cout<<"年龄:"<<con->person[i].age<<"\t"; 
        cout<<"电话:"<<con->person[i].phnum<<"\t";
        cout<<"地址:"<<con->person[i].address<<endl; 
    }
}

void del(Contact*con,int i){
    for(i;i<con->size-1;i++){
        con->person[i]=con->person[i+1];
    }
    con->size--;
}

void modify(Contact* con,string name){
    int i=find(con,name);
    if(i==-1){
        cout<<"查无此人"<<endl;
    }
    else{
        int k=0;
        cout<<"请输入您想更改的信息:"<<endl;
        cout<<"*****  1.姓名  *****"<<endl;
        cout<<"*****  2.性别  *****"<<endl;
        cout<<"*****  3.年龄  *****"<<endl;
        cout<<"*****  4.电话  *****"<<endl;
        cout<<"*****  5.地址  *****"<<endl;
        cout<<"********************"<<endl;
        cin>>k;
        switch(k){
            case 1:{
                string name;
                cout<<"请输入姓名:"<<endl;
                cin>>name;
                con->person[i].name=name;
                cout<<"已修改成功"<<endl;
                break;
            }
            case 2:{
                int sex;
                cout<<"请输入性别:"<<endl<<"1---男性"<<endl<<"2---女性"<<endl;
                while(true){
                    cin>>sex;
                    if(sex==1||sex==2){
                        con->person[i].sex=sex;
                        cout<<"已修改成功"<<endl;
                        break;
                    }
                    else{
                        cout<<"输入错误，请重新输入:"<<endl;
                    }
                }
                break;
            }
            case 3:{
                int age=0;
                cout<<"请输入年龄:"<<endl;
                cin>>age;
                con->person[i].age=age;
                cout<<"已修改成功"<<endl;
                break;
            }
            case 4:{
                string phnum;
                cout<<"请输入电话:"<<endl;
                while(true){
                    cin>>phnum;
                    if(phnum.size()!=11){
                        cout<<"输入长度有误，请重新输入:"<<endl;
                        continue;
                    }
                    else{
                        con->person[i].phnum=phnum;
                        cout<<"已修改成功"<<endl;
                        break;
                    }
                }
                break;
            }
            case 5:{
                string address;
                cout<<"请输入地址:"<<endl;
                cin>>address;
                con->person[i].address=address;
                cout<<"已修改成功"<<endl;
                break;
            }
            default:{
                break;
            }
        }
    }
    system("pause");
    system("cls");
}

void clean(Contact* con){
    con->size=0;    
}

void menu(){
    cout<<"**********通讯录**********"<<endl;
    cout<<"*****  1.添加联系人  *****"<<endl;
    cout<<"*****  2.显示联系人  *****"<<endl;
    cout<<"*****  3.删除联系人  *****"<<endl;
    cout<<"*****  4.查找联系人  *****"<<endl;
    cout<<"*****  5.修改联系人  *****"<<endl;
    cout<<"*****  6.清空联系人  *****"<<endl;
    cout<<"*****  0.退出通讯录  *****"<<endl;
    cout<<"**************************"<<endl;
}

int main(){
    Contact con;
    con.size=0;
    int n=0,k=0;
    while(true){
        menu();
        cin>>n;
        switch(n){
        case 1:{//添加
            add(&con);
            break;
        }
        case 2:{//显示
            show(&con);
            break;
        }
        case 3:{//删除
            if(con.size==0){
                cout<<"无联系人"<<endl;
                break;
            }
            string name;
            cout<<"请输入姓名:"<<endl;
            cin>>name;
            k=find(&con,name);
            if(k==-1){
                cout<<"查无此人"<<endl;
            }
            else{
                del(&con,k);
                cout<<"已删除"<<name<<endl;
            }
            system("pause");
            system("cls");
            break;
        }
        case 4:{//查找
            string name;
            cout<<"请输入姓名:"<<endl;
            cin>>name;
            scan(&con,name);
            system("pause");
            system("cls");
            break;
        }
        case 5:{//修改
            string name;
            cout<<"请输入要更改的联系人姓名:"<<endl;
            cin>>name;
            modify(&con,name);
            break;
        }
        case 6:{//清空
            clean(&con);
            if(con.size==0){
                cout<<"已清空"<<endl;
            }
            system("pause");
            system("cls");
            break;
        }
        case 0:{//退出
            cout<<"欢迎下次使用"<<endl;
            system("pause");
            system("cls");
            return 0;
            break;
        }
        default:{
            break;
        }
    }
    }
    system("pause");//暂停程序的执行，并显示“请按任意键继续”
    return 0;
}