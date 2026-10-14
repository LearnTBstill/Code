#include<iostream>
#include<cmath>
using namespace std;

void prime(int n){
    if(n<=1){
        cout<<"既不是素数也不是合数"<<endl;
        return;
    }
    int m=sqrt(n);
    for(int i=2;i<=m;i++){
        if(n%i==0){
            cout<<"是合数"<<endl;
            return;
        }
    }
    cout<<"是素数"<<endl;
    return;
}

int main(){
    int n=0;
    cout<<"请输入数字："<<endl;
    cin>>n;
    prime(n);
    system("pause");
    system("cls");
    return 0;
}