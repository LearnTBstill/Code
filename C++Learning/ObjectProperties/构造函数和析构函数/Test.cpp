#include<iostream>
using namespace std;

//构造函数的分类和调用 
//两种分类:   1.无参(默认)和有参    2.普通和拷贝
class Person{
    public:
    int age;
    Person(const Person& c){//将传入的人的所有属性拷贝到我身上
        age=c.age;
        cout<<"已调用拷贝构造函数"<<endl;
    }
    Person(){
        cout<<"已调用无参构造函数"<<endl;
    } 
    Person(int a){
        age=a;
        cout<<"已调用有参构造函数"<<endl;
    } 
    ~Person(){
        cout<<"已调用析构函数"<<endl;
    }
};

//三种调用方法
void test1(){
    //括号法
    Person c1;//无参
    Person c2(10);//有参
    Person c3(c1);//拷贝
}

void test2(){
    //显式法
    Person c1=Person(10);
    Person c2=Person(c1);//这样匿名对象就有名了，=左边就是名
    //隐式转换法
    Person c3=10;
    Person c4=c3;//等价于显式，简化了
}

int main(){
    test2();
    return 0;
}



// //对象初始化和清理
// class Person{
//     public://需要在公共作用域下
    
//     //构造函数————进行初始化操作
//     Person(){
//         cout<<"已调用构造函数"<<endl;
//     }   
//     //析构函数————进行清理操作
//     ~Person(){
//         cout<<"已调用析构函数"<<endl;
//     } 
// };

// void test(){
//     Person c1;
// }

// int main(){
//     Person c2;//main函数的栈区，只有在进程结束前调用析构
//     test();//栈区，执行完就调用析构
//     system("pause");
//     return 0;
// }