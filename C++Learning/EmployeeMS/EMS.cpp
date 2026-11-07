#include "EmployeeManage.h"
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
#include<iostream>
using namespace std;

int main(){
    EmployeeManage EM;
    int n=0;
    while(true){
        EM.show_menu();
        cout<<"请输入你的选择："<<endl;
        cin>>n;
        switch(n){
            case 0:{//退出
                EM.exit_system();
                break;
            }
            case 1:{//增加
                EM.addE();
                break;
            }
            case 2:{//显示
                EM.showE();
                break;
            }
            case 3:{//删除
                EM.deleteE();
                break;
            }
            case 4:{//修改
                EM.modify();
                break;
            }
            case 5:{//查找
                break;
            }
            case 6:{//排序
                break;
            }    
            case 7:{//清空
                break;
            }
            default:{
                system("cls");
                break;
            }
        }
    }
    return 0;
}