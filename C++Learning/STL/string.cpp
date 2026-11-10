#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

//string构造函数
int main(){
    string s1;//默认构造  

    const char* str="hello world";
    string s2(str);//有参构造

    string s3(s2);//拷贝构造

    string s4(5,'s');//sssss
}