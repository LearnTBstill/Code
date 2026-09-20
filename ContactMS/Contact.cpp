#include<iostream>
using namespace std;

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
    int n=0;
    while(true){
        menu();
        cin>>n;
        switch(n){
        case 1:{//添加

            break;
        }
        case 2:{//显示

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