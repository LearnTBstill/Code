#include<iostream>
#include<string>
using namespace std;








// class privilege{
//     public:
//     string name="zzz";

//     protected:
//     string car="a";
    
//     private:
//     int password=123123;

//     protected://函数的权限不影响类内访问,只不过如果不是public类外无法访问这个函数
//     void visit(){//类内都可以访问
//         name="aa";
//         car="bb";
//         password=123;
//     }
// };

// int main(){
//     privilege P1;
//     P1.name="cc";//公共权限，类外可以访问
//     P1.car="bb";//被保护权限，类外不可访问
//     P1.password=3333;//私有权限，类外不可访问
// }






// class student{
// public:
//     string name;
//     string num;

//     void assign(){
//         cout<<"请输入名称："<<endl;
//         cin>>name;
//         cout<<"请输入学号："<<endl;
//         cin>>num;
//     }
    
//     void show(){
//         cout<<"姓名为："<<name<<endl;
//         cout<<"学号为："<<num<<endl;
//     }
// };

// int main(){
//     student s1;
//     s1.assign();
//     s1.show();

//     student s2;
//     s2.assign();
//     s2.show();
// }










// const double pi=3.14;
// //创建一个圆类
// class Circle{
//     //访问权限
// public:
    
//     //属性（变量）
//     int r;

//     //行为（函数）
//     double getCircum(){
//         return 2*pi*r;
//     }
// };



// int main(){
//     //通过圆类来创建具体的对象    实例化(通过一个类创建对象)
//     Circle C1;
//     //给对象赋值
//     C1.r=5;
//     //调用行为
//     std::cout<<"圆的周长为："<<C1.getCircum()<<std::endl;
// }
