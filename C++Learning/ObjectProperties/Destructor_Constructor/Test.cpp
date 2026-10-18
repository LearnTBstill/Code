#include<iostream>
using namespace std;

//深拷贝和浅拷贝
class Person{
    public:
    int age,*height;
    Person(){
        cout<<"无参"<<endl;
    }
    Person(int a,int h){
        age=a;
        height=new int(h);
        cout<<"有参"<<endl;
    }
    Person(const Person& c){
        age=c.age;
        //height=c.height;编译器默认的拷贝函数
        height=new int(*c.height);//深拷贝
        cout<<"拷贝"<<endl;
    }
    ~Person(){//析构，释放在堆区开辟的数据
        if(height!=NULL){//new可能开辟不成功返回NULL
            delete height;
            height=NULL;//防止野指针
        }
        cout<<"析构"<<endl;
    }
};

void test1(){
    Person c1(10,150);
    Person c2(c1);
    cout<<c2.age<<endl<<*c2.height<<endl;
}

int main(){
    test1();
    return 0;
}



// //构造函数调用规则
// class Person{
//     public:
//     int age;
//     Person(int a){
//         age=a;
//         cout<<"有参"<<endl;
//     }
// };

// void test(Person c){//编译器自带的拷贝函数就可以传值了
//     Person c1(c);
// }

// int main(){
//     Person c;//用户只定义有参的话这里会报错
//     test(c);
//     return 0;
// }










// //拷贝构造函数的使用
// class Person{
//     public:
//     int age=0;
//     Person(const Person& c){
//         age=c.age;
//         cout<<"已调用拷贝"<<endl;
//     }
//     Person(){
//         cout<<"已调用无参"<<endl;
//     }
//     Person(int a){
//         age=a;
//         cout<<"已调用有参"<<endl;
//     }
//     ~Person(){
//         cout<<"已调用析构"<<endl;
//     }
// };

// //初始化新对象
// void test1(){
//     Person c1(10);
//     Person c2(c1);
//     cout<<c2.age<<endl;
// }

// //值传递给参数传值
// void work(Person c){

// }
// void test2(){
//     Person c;
//     work(c);//值传递的时候会调用拷贝给函数传值
// }

// //值方式返回局部对象（现代编译器不用）
// Person work2(){
//     Person c;
//     return c;
// }

// void test3(){
//     Person c=work2();
// }


// int main(){
//     test1();
//     return 0;
// }


// //构造函数的分类和调用 
// //两种分类:   1.无参(默认)和有参    2.普通和拷贝
// class Person{
//     public:
//     int age;
//     Person(const Person& c){//将传入的人的所有属性拷贝到我身上
//         age=c.age;
//         cout<<"已调用拷贝构造函数"<<endl;
//     }
//     Person(){
//         cout<<"已调用无参构造函数"<<endl;
//     } 
//     Person(int a){
//         age=a;
//         cout<<"已调用有参构造函数"<<endl;
//     } 
//     ~Person(){
//         cout<<"已调用析构函数"<<endl;
//     }
// };

// //三种调用方法
// void test1(){
//     //括号法
//     Person c1;//无参
//     Person c2(10);//有参
//     Person c3(c1);//拷贝
// }

// void test2(){
//     //显式法
//     Person c1=Person(10);
//     Person c2=Person(c1);//这样匿名对象就有名了，=左边就是名
//     //隐式转换法
//     Person c3=10;
//     Person c4=c3;//等价于显式，简化了
// }

// int main(){
//     test2();
//     return 0;
// }



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