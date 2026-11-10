#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;


// //vector容器嵌套容器
// int main(){
//     vector<vector<int>> v;
//     //创建小容器
//     vector<int> v1;vector<int> v2;vector<int> v3;
//     for(int i=0;i<4;i++){
//         v1.push_back(i+1);v2.push_back(i+2);v3.push_back(i+3);
//     }
//     //插入大容器
//     v.push_back(v1);v.push_back(v2);v.push_back(v3);
//     //遍历所有数据
//     for(vector<vector<int>>::iterator it=v.begin();it!=v.end();it++){
//         for(vector<int>::iterator ite=(*it).begin();ite!=(*it).end();ite++){
//             cout<<*ite<<"   ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }




// //vector存放自定义数据类型
// class Person{
//     public:
//     Person(string name,int age){
//         this->name=name;
//         this->age=age;
//     }
//     string name;
//     int age;
// };

// void test1(){
//     vector<Person> v;
//     Person p1("刘",21);Person p2("关",25);Person p3("张",27);
//     v.push_back(p1);v.push_back(p2);v.push_back(p3); 
//     //遍历
//     for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
//         cout<<(*it).name<<"  "<<it->age<<endl;//解it之后是Person
//     }
// }

// void test2(){
//     vector<Person*> v;//存放指针的数组
//     Person p1("刘",21);Person p2("关",25);Person p3("张",27);
//     v.push_back(&p1);v.push_back(&p2);v.push_back(&p3);
//     //遍历
//     for(vector<Person*>::iterator it=v.begin();it!=v.end();it++){
//         cout<<(*(*it)).name<<"   "<<(*it)->age<<endl;//*it是一个指针，再->
//     }
// }

// int main(){
//     test1();
//     test2();
//     return 0;
// }



//vector存放内置数据类型
// void Print(int val){
//     cout<<val<<endl;
// }

// int main(){
//     //创建vector
//     vector<int> v;
//     //追加数据
//     v.push_back(1);
//     v.push_back(2);
//     v.push_back(5);
//     //通过迭代器访问数据
//     vector<int>::iterator iteBegin=v.begin();//vector<int>作用域下的iterator(一个内部类)
//     vector<int>::iterator iteEnd=v.end();
//     //第一种遍历方式
//     while(iteBegin!=iteEnd){
//         cout<<*iteBegin<<endl;
//         iteBegin++;
//     }
//     //第二种遍历方式(常用)
//     for(vector<int>::iterator it=v.begin();it!=v.end();it++){
//         cout<<*it<<endl;
//     }
//     //第三种遍历方式(STL提供的遍历算法)
//     for_each(v.begin(),v.end(),Print);
// }