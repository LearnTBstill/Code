#include<iostream>   
#include<map>
#include<string>
using namespace std;

//一个案例巩固STL容器











// class Compare{
//     public:
//     bool operator()(int k1,int k2){
//         return k1>k2;
//     }
// };

// void PrintM(const map<int,int,Compare>& m){
//     for(map<int,int,Compare>::const_iterator ite=m.begin();ite!=m.end();ite++){
//         cout<<(*ite).first<<","<<(*ite).second<<"   ";
//     }
//     cout<<endl;
// }

// int main(){
//     map<int,int,Compare> m;
//     m.insert(make_pair(1,4));m.insert(make_pair(5,2));m.insert(make_pair(7,1));m.insert(make_pair(3,3));
//     PrintM(m);//7,1   5,2   3,3   1,4
// }





// //插入删除
// int main(){
//     map<int,int> m;
//     //第一种插入
//     m.insert(pair<int,int>(1,10));
//     //第二种插入
//     m.insert(make_pair(2,20));
//     //第三种插入
//     m.insert(map<int,int>::value_type(3,30));
//     //第四种插入
//     m[4]=40;

//     cout<<m[4]<<endl;

//     //删除
//     m.erase(m.begin());//删除第一个
//     m.erase(3);//按照key删除
//     m.erase(m.begin(),m.end());//区间删除
    
//     //清空
//     m.clear();   
// }





// //构造
// int main(){
//     map<int,int>m;
    
//     //插入
//     m.insert(pair<int,int>(3,50));m.insert(pair<int,int>(2,20));
//     m.insert(pair<int,int>(5,30));m.insert(pair<int,int>(1,10));
//     PrintM(m);//1,10   2,20   3,50   5,30

//     //拷贝构造
//     map<int,int>m2(m);
//     PrintM(m2);

//     //operator=赋值
//     map<int,int>m3=m;
//     PrintM(m3);
// }