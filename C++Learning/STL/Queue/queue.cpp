#include<queue>
#include<iostream>
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

int main(){
    queue<Person> q;
    Person p1("张",22);Person p2("刘",26);Person p3("王",32);
    
    //入队
    q.push(p1);q.push(p2);q.push(p3);

    //只要队不为空，显示队头队尾，出队
    while(!q.empty()){//判空
        cout<<q.front().name<<"   ";   cout<<q.front().age<<endl;
        cout<<q.back().name<<"   ";    cout<<q.back().age<<endl;

        q.pop();
    }

    cout<<q.size()<<endl;
}