#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//








// //二元谓词
// class MyCompare{
//     public:
//     bool operator()(int v1,int v2){
//         return v1>v2;
//     }
// };
// int main(){
//     vector<int> v;
//     v.push_back(1);v.push_back(9);v.push_back(5);
//     sort(v.begin(),v.end());//升序

//     //用函数对象改降序
//     sort(v.begin(),v.end(),MyCompare());//降序
// }







// //一元谓词
// class MyC{
//     public:
//     bool operator()(int val){
//         return val>5;
//     }
// };
// int main(){
//     vector<int> v;
//     for(int i=0;i<10;i++){
//         v.push_back(i);
//     }
    
//     vector<int>::iterator ite=find_if(v.begin(),v.end(),MyC());
//     if(ite==v.end()){
//         cout<<"未找到"<<endl;
//     }
//     else{
//         cout<<"找到"<<endl;
//     }
// }






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