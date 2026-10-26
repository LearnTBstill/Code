#include<iostream>
#include<string>
using namespace std;
















// //成员函数作友元
// class Building;
// class Person{
//     public:
//     Person();
//     void visit1();//可以访问Building中私有的
//     void visit2();//不可以访问Building中私有的
//     Building *B;
// };
// class Building{
//     friend void Person::visit1();//成员函数作友元
//     public:
//     Building();
//     string sittingroom;
//     private:
//     string bedroom;
// };

// Building::Building(){
//     sittingroom="客厅";
//     bedroom="卧室";
// }

// Person::Person(){
//     B=new Building;
// }

// void Person::visit1(){
//     cout<<"visit1正在访问:"<<B->sittingroom<<endl;
//     cout<<"visit1正在访问:"<<B->bedroom<<endl;
// }

// void Person::visit2(){
//     cout<<"visit2正在访问:"<<B->sittingroom<<endl;
//     cout<<"visit2正在访问:"<<B->bedroom<<endl;//不是Building的友元，没法访问
// }

// void test(){
//     Person p;
//     p.visit1();
//     p.visit2();
// }

// int main(){
//     test();
// }


// //友元类
// class Building;
// class Person{
//     public:
//     Person();
//     void visit();
//     Building *B;//用指针是因为没定义只声明这个类的话编译器不知道给它分多少内存，而指针大小是固定的  
// };              //当然后面还是定义了2333
// class Building{
//     friend class Person;//类作友元
//     public:
//     Building();
//     string sittingroom;
//     private:
//     string bedroom;
// };

// //类外实现成员函数
// Building::Building (){
//     sittingroom="客厅";
//     bedroom="卧室";
// }

// Person::Person(){
//     B=new Building;//指针的话一定要用new在堆区开辟，不然Person()结束后会出现空指针
// }

// void Person::visit(){
//     cout<<"Person正在访问:"<<B->sittingroom<<endl;
//     cout<<"Person正在访问:"<<B->bedroom<<endl;//Person是Building的友元类所以可以访问
// }

// void test(){
//     Person p;
//     p.visit();
// }

// int main(){
//     test();
// }


// //友元
// class Buildings{
//     friend void visit(Buildings &B);//好朋友，允许访问
//     public:
//     Buildings(){
//         sittingroom="客厅";
//         bedroom="卧室";
//     }
//     string sittingroom;
//     private:
//     string bedroom;
// };

// void visit(Buildings &B){
//     cout<<"访问客厅："<<B.sittingroom<<endl;
//     cout<<"访问卧室："<<B.bedroom<<endl;//不变成友元的话不能访问私有
// }

// void test(){
//     Buildings B;
//     visit(B);
// }

// int main(){
//     test();
//     return 0;
// }


// //const修饰成员函数
// class Person{
//     public:

//     //常函数
//     //在成员函数后const，就是修改this，让this指针指向的值也不可改了
//     void test1()const{
//         A=10;//默认是this.A
//         this=NULL;//不能修改指向
//         B=10;//mutable
//     }

//     //mutable关键字
//     mutable int B;//即使在常里也可以修改  

//     void test11(){}
//     int A;
// };

// int test2(){
//     //常对象
//     const Person p;
//     p.A=5;//const
//     p.B=10;//mutable

//     p.test1();//常对象只能调用常函数
//     p.test11();//如果能调用普通成员函数，不就侧面打破了不能修改值的规定
// }




// //空指针访问成员函数
// class Person{
//   public:
//   void test1(){//不会报错
//     cout<<"调用1"<<endl;
//   }
//   void test2(){//会报错
//     //if(this==NULL){return;}增加鲁棒性
//     cout<<A<<endl;//默认是this->A,传入的指针是NULL
//   }
//   int A;  
// };

// int main(){
//     Person *p=NULL;
//     p->test1();
//     p->test2();
//     return 0;
// }



// //this指针 
// class Person{
//     public:
//     Person(int age){
//         //this指向 被调用的成员函数 所属的对象
//         this->age=age;//age=age的话没法分辨是哪个
//     }
//     int age;
//     Person& PersonADD(Person& p){//用引用返回其本体
//         this->age+=p.age;
//         return *this;//指向p1本体
//     }
// };

// //解决名称冲突
// void test1(){
//     Person p1(20);
// }

// //返回对象用*this
// void test2(){
//     Person p1(10);
//     Person p2(5);
//     p1.PersonADD(p2).PersonADD(p2).PersonADD(p2);//如果PersonADD(p2)返回值是p1,不就可以实现x.x.x.x,多次加
//     cout<<p1.age<<endl;//25
// }

// int main(){
//     test2();
//     return 0;
// }
// class Human{//大小为4
//     public:
//     static int A;//静态成员变量,不属于类的对象
//     int B;
//     void test(){//非静态成员函数，不属于类的对象
        
//     }
//     static void test2(){//静态成员函数，不属于类的对象

//     }
// };

// int Human::A=5;

// class Person{//空对象

// };

// void test1(){
//     Person p1;
//     //编译器会给每个空对象分配1B，他们有自己的地址，用于区分
//     cout<<sizeof(p1)<<endl;//1
// }

// int main(){
//     test1();
//     return 0;
// }







// //静态成员函数
// class Person{
//     public:
//     static void func(){
//         A=7;//静态成员函数可以访问静态成员变量
//         B=5;//静态成员函数不可以访问普通成员变量
//         cout<<"调用静态成员函数"<<endl;
//     }
//     static int A;
//     int B;
// };

// int Person::A=5;

// void test(){
//     //可以用对象访问
//     Person p;
//     p.func();
//     //也是可以用类名访问，因为所有对象共享同一个函数
//     Person::func();
// }

// int main(){
//     test();
//     return 0;
// }




// //静态成员变量
// class Person{
//     public:
//     static int A;//类内声明
    
//     //静态成员变量也是有访问权限的
//     private:
//     static int B;
// };

// int Person::A=5;//类外初始化
// int Person::B=9;//私有也要初始化

// void test1(){
//     Person p1;
//     cout<<p1.A<<endl;//5
//     Person p2;
//     p2.A=10;
//     cout<<p1.A<<endl;//10
//     //而且可以通过类名来访问它
//     cout<<Person::A<<endl;//10
//     cout<<Person::B<<endl;//私有的访问不了
// }

// int main(){
//     test1();
//     return 0;
// }







// //类对象作为类的成员
// class Phone{
//     public:
//     Phone(string n){
//         num=n;
//         cout<<"Phone构造"<<endl;
//     }
//     ~Phone(){
//         cout<<"Phone析构"<<endl;
//     }
//     string num;
// };
// class Person{
//     public:
//     //Phone p=pnum;隐式转换法的初始化，Phone的构造函数是有参
//     Person(string n,string pnum):name(n),p(pnum){
//         cout<<"Person构造"<<endl;
//     }
//     ~Person(){
//         cout<<"Person析构"<<endl;
//     }
//     string name;
//     Phone p;
// };

// void test(){
//     Person p1("zkw","131");
// }

// int main(){
//     test();
//     return 0;
// }



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





