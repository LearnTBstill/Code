#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//find







// //transform
// class Trans{
//     public:
//     int operator()(int val){
//         return val;
//     }
// };

// class MyPrint{
//     public:
//     void operator()(int val){
//         cout<<++val<<" ";
//     }
// };

// int main(){
//     vector<int>v;
//     for(int i=0;i<10;i++){
//         v.push_back(i);
//     }
//     vector<int>target;
    
//     //提前设定大小
//     target.resize(v.size());

//     transform(v.begin(),v.end(),target.begin(),Trans());
//     for_each(target.begin(),target.end(),MyPrint());
//     cout<<endl;
// }





// //for_each
// void PrintV(int val){
//     cout<<val<<" ";
// }

// class MyPrint{
//     public:
//     void operator()(int val){
//         cout<<val<<" ";
//     }
// };

// int main(){
//     vector<int> v;
//     for(int i=0;i<10;i++){
//         v.push_back(i);
//     }

//     for_each(v.begin(),v.end(),PrintV);
//     cout<<endl;

//     for_each(v.begin(),v.end(),MyPrint());
//     cout<<endl;
// }