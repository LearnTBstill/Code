#include<iostream>
#include<string>
using namespace std;

//类对象作为类的成员
class Phone{
    public:
    Phone(string n){
        num=n;
        cout<<"Phone构造"<<endl;
    }
    ~Phone(){
        cout<<"Phone析构"<<endl;
    }
    string num;
};
class Person{
    public:
    //Phone p=pnum;隐式转换法的初始化，Phone的构造函数是有参
    Person(string n,string pnum):name(n),p(pnum){
        cout<<"Person构造"<<endl;
    }
    ~Person(){
        cout<<"Person析构"<<endl;
    }
    string name;
    Phone p;
};

void test(){
    Person p1("zkw","131");
}

int main(){
    test();
    return 0;
}



// //初始化列表
// class Person{
//     public:
//     int A;
//     int B;
//     int C;
//     //传统构造函数初始化
//     // Person(int a,int b,int c){
//     //     A=a;B=b;C=c;
//     // }

//     //初始化列表
//     Person():A(11),B(22),C(33){

//     }
//     Person(int a,int b,int c):A(a),B(b),C(c){

//     }
// };

// int main(){
//     // Person c(10,20,30);
//     Person c1;
//     Person c2(10,20,30);
//     cout<<c1.A<<" "<<c1.B<<" "<<c1.C<<" "<<endl;
//     cout<<c2.A<<" "<<c2.B<<" "<<c2.C<<" "<<endl;
//     return 0;
// }





