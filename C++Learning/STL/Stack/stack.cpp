#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;

int main(){
    stack<int>s;
    //入栈
    s.push(10);s.push(20);s.push(30);s.push(40);s.push(50);
    //只要不为空，返回栈顶，并出栈
    while(!s.empty()){//判空
        cout<<s.top()<<endl;//查看栈顶
        s.pop();//出栈，没有返回值
    }
    //大小
    cout<<s.size()<<endl;//0

    //拷贝构造
    stack<int>s2(s);
    //=
    stack<int>s3=s2;
}