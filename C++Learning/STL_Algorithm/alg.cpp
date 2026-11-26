#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//adjacent_find
int main(){
    vector<int> v;
    v.push_back(0);v.push_back(2);v.push_back(0);v.push_back(3);
    v.push_back(1);v.push_back(4);v.push_back(3);v.push_back(3);
    vector<int>::iterator ite=adjacent_find(v.begin(),v.end());
    if(ite==v.end()){
        cout<<"未找到相邻重复元素"<<endl;
    }
    else{
        cout<<*ite<endl;
    }
}







// class Person{
//     public:
//     Person(string name,int age){
//         this->name=name;
//         this->age=age;
//     }
//     string name;
//     int age;
// };

// //find_if
// class GreaterFive{
//     public:
//     bool operator()(int val){
//         return val>5;
//     }
// };
// void test1(){
//     vector<int>v;
//     for(int i=0;i<10;i++){
//         v.push_back(i);
//     }
//     vector<int>::iterator ite=find_if(v.begin(),v.end(),GreaterFive());
//     if(ite==v.end()){
//         cout<<"未找到"<<endl;
//     }
//     else{
//         cout<<*ite<<endl;
//     }
// }

// class Greater20{
//     public:
//     bool operator()(const Person& p){
//         return p.age>20;
//     }
// };
// void test2(){
//     vector<Person> v;
//     Person p1("张",20);v.push_back(p1);
//     Person p2("李",40);v.push_back(p2);
//     Person p3("王",10);v.push_back(p3);
//     //找是否有大于年龄20的
//     vector<Person>::iterator ite=find_if(v.begin(),v.end(),Greater20());
//     if(ite==v.end()){
//         cout<<"未找到"<<endl;
//     }
//     else{
//         cout<<(*ite).name<<"   "<<(*ite).age<<endl;
//     }
// }

// int main(){
//     test1();
//     test2();
// }




// //find
// void test1(){//内置数据类型
//     vector<int>v;
//     for(int i=0;i<10;i++){
//         v.push_back(i);
//     }
//     //查找5
//     vector<int>::iterator ite=find(v.begin(),v.end(),5);
//     cout<<*ite<<endl;//5
// }

// class Person{
//     public:
//     Person(string name,int age){
//         this->name=name;
//         this->age=age;
//     }
//     bool operator==(const Person& p){//重载==
//         if(this->name==p.name&&this->age==p.age){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
//     string name;
//     int age;
// };
// void test2(){//自定义数据类型
//     vector<Person> v;
//     Person p1("张",20);v.push_back(p1);
//     Person p2("李",40);v.push_back(p2);
//     Person p3("王",10);v.push_back(p3);
//     vector<Person>::iterator ite=find(v.begin(),v.end(),p2);
//     if(ite==v.end()){//不重载==会报错
//         cout<<"查无此人"<<endl;
//     }
//     else{
//         cout<<(*ite).name<<"   "<<(*ite).age<<endl;
//     }
// }

// int main(){
//     test1();
//     test2();
// }






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