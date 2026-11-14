#include<list>
#include<iostream>
#include<algorithm>
using namespace std;

class Person{
    public:
    Person(string name,int height,int age){
        this->name=name;
        this->height=height;
        this->age=age;
    }
    string name;
    int height;
    int age;
};

void PrintL(const list<Person>& l){
    for(list<Person>::const_iterator ite=l.begin();ite!=l.end();ite++){
        cout<<(*ite).name<<"   "<<(*ite).height<<"   "<<(*ite).age<<endl;
    }
    cout<<endl;
}

bool CompareP(Person& p1,Person& p2){
    if(p1.age!=p2.age){
        return p1.age<p2.age;
    }
    else{
        return p1.height>p2.height;
    }
}

int main(){
    list<Person>l;
    Person p1("张",188,22);Person p2("周",150,15);Person p3("刘",188,50);Person p4("焦",170,22);
    l.push_back(p1);l.push_back(p2);l.push_back(p3);l.push_back(p4);

    //年龄升序，相同则身高降序
    l.sort(CompareP);
    PrintL(l);
}











// bool myCompare(int v1,int v2){
//     return v1>v2;
// }

// //反转和排序
// int main(){
//     list<int> l;
//     l.push_front(1);l.push_back(2);l.push_front(3);l.push_back(5);l.push_back(4);
//     PrintL(l);//3 1 2 5 4

//     //反转
//     l.reverse();
//     PrintL(l);//4 5 2 1 3

//     //排序
//     // sort(l.begin(),l.end());//运行会报错
//     l.sort();
//     PrintL(l);//1 2 3 4 5

//     //自定义排序规则
//     l.sort(myCompare);
//     PrintL(l);//5 4 3 2 1
// }







// //验证list的迭代器不支持随机访问
// int main(){
//     list<int> l;
//     list<int>::iterator ite=l.begin();
//     ite++;   ite--;//支持双向
//     ite=ite+1;
//     ite=ite+3;//不支持随机访问
// }






// int main(){
//     list<int> l;
//     l.push_front(10);l.push_back(20);l.push_front(30);l.push_back(30);l.push_back(40);
//     PrintL(l);//30 10 20 30 40

//     //remove
//     l.remove(30);
//     PrintL(l);//10 20 40     
// }