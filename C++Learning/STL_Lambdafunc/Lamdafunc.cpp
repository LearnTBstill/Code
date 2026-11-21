#include<iostream>
#include<string>
using namespace std;

class MyAdd{
    public:
    int operator()(int v1,int v2){
        return v1+v2;
    }
};
void test1(){
    MyAdd myadd;
    cout<<myadd(10,20)<<endl;//30
}

class MyPrint{
    public:
    void operator()(string s){
        cout<<s<<endl;
    }
};
void test2(){
    MyPrint mp;
    mp("Hello");
    mp("Hello");
    mp("Hello");
}

int main(){
    test1();
    test2();
}