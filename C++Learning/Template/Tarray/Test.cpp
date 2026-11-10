#include<iostream>
#include "MyArray.hpp"
using namespace std;

void test1(){
    MyArray<int> m1(5);//有参
    MyArray<int> m2(m1);//拷贝
    MyArray<int> m3(100);//有参
    m3=m2;//=
}

void Print(MyArray<int>& arr){
    for(int i=0;i<arr.rS();i++){
        cout<<arr[i]<<" ";//重载过[]所以可以访问
    }
    cout<<endl;
}

//对内置数据类型的测试
void test2(){
    MyArray<int> arr(5);
    for(int i=0;i<5;i++){
        arr.Push_back(i);
    }
    Print(arr);
    cout<<"容量："<<arr.rC()<<endl;
    cout<<"大小："<<arr.rS()<<endl;

    MyArray<int> arr2(arr);
    Print(arr2);
    arr2.delete_back();
    Print(arr2);
    cout<<"容量："<<arr2.rC()<<endl;
    cout<<"大小："<<arr2.rS()<<endl;
}

class Person{
    public:
    Person(){};
    Person(string name,int age){
        this->name=name;
        this->age=age;
    }
    string name;
    int age;
};
void PrintPerson(MyArray<Person>& arr){
    for(int i=0;i<arr.rS();i++){
        cout<<arr[i].name<<" "<<arr[i].age<<endl;
    }
    cout<<endl;
}
//对自定义数据类型的测试
void test3(){
    MyArray<Person> arr(10);
    Person p1("张",20);Person p2("刘",22);Person p3("焦",25);
    arr.Push_back(p1);arr.Push_back(p2);arr.Push_back(p3);
    PrintPerson(arr);
    cout<<"容量："<<arr.rC()<<endl;
    cout<<"大小："<<arr.rS()<<endl;
}

int main(){
    test1();
    test2();
    test3();
    return 0;
}