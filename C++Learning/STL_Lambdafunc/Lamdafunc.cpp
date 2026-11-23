#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

//内建函数对象————逻辑仿函数
void PrintV(vector<bool>& v){
    for(vector<bool>::iterator ite=v.begin();ite!=v.end();ite++){
        cout<<*ite<<" ";
    }
    cout<<endl;
}

int main(){
    vector<bool> v;
    v.push_back(true);v.push_back(false);v.push_back(true);v.push_back(false);
    PrintV(v);//1 0 1 0

    //利用逻辑非，搬运到v2，并进行取反
    vector<bool> v2;
    v2.resize(v.size());//提前设置空间不然搬运失败
    transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());
    PrintV(v2);//0 1 0 1
}








// //内建函数对象————关系仿函数
// void PrintV(vector<int>& v){
//     for(vector<int>::iterator ite=v.begin();ite!=v.end();ite++){
//         cout<<*ite<<"   ";
//     }
//     cout<<endl;
// }

// class MyCompare{
//     public:
//     bool operator()(int val1,int val2){
//         return val1>val2;
//     }
// };

// int main(){
//     vector<int> v;
//     v.push_back(5);v.push_back(1);v.push_back(9);
//     PrintV(v);//5   1   9
//     //用自建的实现
//     sort(v.begin(),v.end(),MyCompare());
//     PrintV(v);//9   5   1
//     //用内建的实现
//     sort(v.begin(),v.end(),greater<int>());
//     PrintV(v);//9   5   1
// }








// //内建函数对象————算术仿函数
// int main(){
//     //negate取反
//     negate<int>n;
//     cout<<n(50)<<endl;//-50

//     //plus加法
//     plus<int>p;
//     cout<<p(25,5)<<endl;//30

//     //minus减法
//     minus<int>m;
//     cout<<m(5,10)<<endl;//-5

//     //multiplies乘法
//     multiplies<int>mul;
//     cout<<mul(5,-1)<<endl;//-5

//     //divides除法
//     divides<int>d;
//     cout<<d(-6,5)<<endl;//-1

//     //modulus取模
//     modulus<int>mod;
//     cout<<mod(100,3)<<endl;//1
// }








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