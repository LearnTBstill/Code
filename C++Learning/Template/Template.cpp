#include<iostream>
#include<string>
using namespace std;












// //函数模板注意事项

// //自动推导的话，必须推导出一致的数据类型才可以使用
// template<typename T>
// void func1(int &a,double &b){
    
// }

// void test1(){
//     int a=5;double b=1.2;
//     func1(a,b);//自动推导到不相同会报错
// }

// //模板必须要确认T的数据类型才可以使用
// template<typename T>
// void func2(){
    
// }

// void test2(){
//     func2();//即便是空实现也需要告诉他是什么
//     func2<int>();//随便给一个
// }






// //交换两个int
// void swapInt(int &a,int &b){
//     int temp=a;
//     a=b;
//     b=temp;
// }

// //交换两个double
// void swapDouble(double &a,double &b){
//     double temp=a;
//     a=b;
//     b=temp;
// }

// //有那么多数据类型，难道都要一个个写吗
// //所以使用函数模板
// template<typename T>
// void MySwap(T &a,T &b){
//     T temp=b;
//     b=a;
//     a=temp;
// }

// int main(){
//     int a=10;
//     int b=20;

//     //两种方式使用函数模板
//     MySwap(a,b);

//     MySwap<int>(a,b);

//     cout<<"a="<<a<<endl;
//     cout<<"b="<<b<<endl;
// }