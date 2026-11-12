#include<deque>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//前三个容器学习的总结案例
class Person{
    public:
    Person(string name,int avgscore){
        this->name=name;
        this->avgscore=avgscore;
    }
    string name;
    int avgscore;
};

void createP(vector<Person>& v){
    string str="ABCDE";
    for(int i=0;i<5;i++){
        string name="选手";
        name+=str[i];
        int score=0;
        Person p(name,score);
        v.push_back(p);
    }
}

void setScore(vector<Person>& v){
    for(vector<Person>::iterator ite=v.begin();ite!=v.end();ite++){
        deque<int>d;
        //写入分数
        for(int i=0;i<10;i++){
            int score=rand()%41+60;                     //C语言的伪随机数生成器，它的生成范围很大
            d.push_back(score);
        }
        //排序
        sort(d.begin(),d.end());
        //去除最高最低分
        d.pop_front();d.pop_back();
        //取平均
        int sum=0;
        for(deque<int>::iterator ite2=d.begin();ite2!=d.end();ite2++){
            sum+=(*ite2);
        }
        int avg=sum/d.size();
        //赋值
        (*ite).avgscore=avg;
    }
}

void showScore(vector<Person>& v){
    for(vector<Person>::iterator it=v.begin();it!= v.end();it++){
        cout<<"姓名："<<(*it).name<<"平均分："<<it->avgscore<<endl;
    }
}

int main(){
    vector<Person> v;
    createP(v); 
    setScore(v);
    showScore(v);
}








// void Printdequie(const deque<int>& d){
//     for(deque<int>::const_iterator ite=d.begin();ite!=d.end();ite++){
//         cout<<*ite<<",";
//     }
//     cout<<endl;
// }
// //deque排序
// int main(){
//     deque<int> d;
//     d.push_front(10);d.push_back(30);d.push_front(20);
//     Printdequie(d);//20,10,30,

//     //排序
//     sort(d.begin(),d.end());
//     Printdequie(d);//10,20,30,
// }







// //想要限定只读
// void Printdeque(const deque<int>& dq){
//     for(deque<int>::const_iterator ite=dq.begin();ite!=dq.end();ite++){
//         cout<<*ite<<endl;
//         *ite=10;//只读了
//     }
// }