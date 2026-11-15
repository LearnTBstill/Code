#include<set>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

class Person{
    public:
    Person(string name,int age){
        this->name=name;
        this->age=age;
    }
    string name;
    int age;
};

class Mycompare{//自定义的排序方法
    public:
    bool operator()(const Person& p1,const Person& p2){
        return p1.age>=p2.age;
    }
};

void PrintS1(const set<Person>& s){
    for(set<Person>::const_iterator ite=s.begin(); ite!=s.end();ite++){
        cout<<(*ite).name<<" "<<(*ite).age<<endl;
    }
}
void PrintS2(const set<Person,Mycompare>& s){
    for(set<Person,Mycompare>::const_iterator ite=s.begin(); ite!=s.end();ite++){
        cout<<(*ite).name<<" "<<(*ite).age<<endl;
    }
}

//set排序————自定义数据类型
int main(){
    Person p1("张",25);Person p2("周",15);Person p3("刘",60);

    // set<Person> s1;//没法运行
    // s1.insert(p1);s1.insert(p2);s1.insert(p3);
    // PrintS1(s1);

    set<Person,Mycompare> s2;
    s2.insert(p1);s2.insert(p2);s2.insert(p3);
    PrintS2(s2);//可以输出了
}








// class Mycompare{
//     public:
//     bool operator()(int a,int b){
//         return a>b;
//     }
// };

// //set排序————内置数据类型
// int main(){
//     //默认
//     set<int> s;
//     s.insert(5);s.insert(7);s.insert(1);
//     PrintS(s);//1 5 7

//     //改降序
//     set<int,Mycompare> s2;
//     s2.insert(5);s2.insert(7);s2.insert(1);
//     for(set<int,Mycompare>::iterator ite=s2.begin();ite!=s2.end();ite++){
//         cout<<*ite<<" ";//7 5 1
//     }
//     cout<<endl;
// }







// //对组pair的创建与输出
// int main(){
//     //第一种方式
//     pair<string,int> p1("张",22);
//     cout<<p1.first<<"  "<<p1.second<<endl;//张  22

//     //第二种方式
//     pair<string,int> p2=make_pair("张",22);
//     cout<<p2.first<<"  "<<p2.second<<endl;//张  22
// }





// //set和multiset区别
// int main(){
//     //set
//     set<int> s;        
//     pair<set<int>::iterator,bool> p=s.insert(5);//返回值是pair对组
//     if(p.second){//第二个数据，也就是bool
//         cout<<"插入成功"<<endl;//第一次插入成功
//     }
//     else{
//         cout<<"插入失败"<<endl;
//     }
//     p=s.insert(5);
//     if(p.second){
//         cout<<"插入成功"<<endl;
//     }
//     else{
//         cout<<"插入失败"<<endl;//第二次插入失败
//     }

//     //multiset
//     multiset<int> ms;
//     ms.insert(5);ms.insert(5);//它的返回值直接就是一迭代器，不判断成功与否
//     PrintS(ms);//5 5
// }







// //查找和统计
// int main(){
//     set<int> s;
//     s.insert(5);s.insert(15);s.insert(10);s.insert(20);s.insert(10);

//     //查找
//     set<int>::iterator pos=s.find(15);
//     if(pos!=s.end()){
//         cout<<*pos<<endl;
//     }
//     else{
//         cout<<"未找到"<<endl;
//     }

//     //统计
//     int num=s.count(10);
//     cout<<num<<endl;//1
// }








// //插入和删除
// int main(){
//     set<int> s;
    
//     //插入
//     s.insert(1);s.insert(8);s.insert(5);s.insert(5);s.insert(10);
//     PrintS(s);//1 5 8 10   自动排序，不重复

//     //删除
//     s.erase(s.begin());//删除第一个
//     PrintS(s);//5 8 10
//     s.erase(8);//删除8
//     PrintS(s);//5 10
    
//     //清空
//     s.clear();
// }