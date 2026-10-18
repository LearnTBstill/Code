#include<iostream>
using namespace std;

//初始化列表
class Person{
    public:
    int A;
    int B;
    int C;
    //传统构造函数初始化
    // Person(int a,int b,int c){
    //     A=a;B=b;C=c;
    // }

    //初始化列表
    Person():A(11),B(22),C(33){

    }
    Person(int a,int b,int c):A(a),B(b),C(c){

    }
};

int main(){
    // Person c(10,20,30);
    Person c1;
    Person c2(10,20,30);
    cout<<c1.A<<" "<<c1.B<<" "<<c1.C<<" "<<endl;
    cout<<c2.A<<" "<<c2.B<<" "<<c2.C<<" "<<endl;
    return 0;
}





