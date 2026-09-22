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
        con->person[con->size].name=name;//con->person[con->size++]取出来的是实体而非指针所以用"."
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

void show(Contact con){

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

    int n=0;
    while(true){
        menu();
        cin>>n;
        switch(n){
        case 1:{//添加
            add(&con);
            break;
        }
        case 2:{//显示
            show(con);
            break;
        }
        case 3:{//删除

            break;
        }
        case 4:{//查找

            break;
        }
        case 5:{//修改

            break;
        }
        case 6:{//清空

            break;
        }
        case 0:{//退出
            cout<<"欢迎下次使用"<<endl;
            system("pause");
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