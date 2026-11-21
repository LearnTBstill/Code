#include<iostream>
#include<string>
using namespace std;










// //基本使用1 
// class MyAdd{
//     public:
//     int operator()(int v1,int v2){
//         return v1+v2;
//     }
// };
// void test1(){
//     MyAdd myadd;
//     cout<<myadd(10,20)<<endl;//30
// }

// //基本使用2 
// class MyPrint{
//     public:
//     MyPrint(){
//         this->count=0;
//     }
//     void operator()(string s){
//         cout<<s<<endl;
//         this->count++;
//     }
//     int count;
// };
// void test2(){
//     MyPrint mp;
//     mp("Hello");
//     mp("Hello");
//     mp("Hello");
//     cout<<mp.count<<endl;//3
// }

// //基本使用3
// void doPrint(MyPrint& mp,string s){
//     mp(s);
// }
// void test3(){
//     MyPrint mp;
//     doPrint(mp,"abc");
// }

// int main(){
//     test1();
//     test2();
//     test3();
// }