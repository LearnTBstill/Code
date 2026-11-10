#include<iostream>
#include<string>
using namespace std;
template<class T1,class T2>
class Person;

//类外实现
template<class T1,class T2>
void PrintPerson2(Person<T1,T2> &p){//不用加作用域因为是全局函数
    cout<<p.name<<"   类外   "<<p.age<<endl;
}

//类模板与友元
template<class T1,class T2>
class Person{
    //全局函数 类内实现
    friend void PrintPerson1(Person<T1,T2> &p){
        cout<<p.name<<"   "<<p.age<<endl;
    }
    //全局函数 类外实现
    friend void PrintPerson2<>(Person<T1,T2> &p);

    public:
    Person(T1 name,T2 age){
    this->name=name;
    this->age=age;
}
    private:
    T1 name;
    T2 age;
};

//全局函数在类内实现
void test1(){
    Person<string,int> p("ggg",123);
    PrintPerson1(p); 
}

//全局函数在类外实现
void test2(){
    Person<string,int> p("ggg",123);
    PrintPerson2(p);//出错了
}


int main(){
    test1();
    test2();
    return 0;
}




// //类模板分文件编写
// int main(){
//     Person<string,int> p("aaa",20);
//     p.show();
// }





// //类模板成员函数类外实现
// template<class T1,class T2>
// class Person{
//     Person(T1 name,T2 age);
//     void show();
//     T1 name;
//     T2 age;
// };

// //构造函数类外实现
// template<class T1,class T2>
// Person<T1,T2>::Person(T1 name,T2 age){//没有<T1,T2>就是普通函数的类外实现了
//     this->name=name;
//     this->age=age;
// }

// template<class T1,class T2>
// void Person<T1,T2>::show(){
//     cout<<this->name<<"   "<<this->age<<endl;
// }




// //类模板与继承
// template<class T>
// class Father{
//     T m;
// };

// class Son:public Father{//必须指定父类中T的类型，才能继承
// };
// class Son:public Father<int>{//直接指定，但是缺少灵活度
// };



// //如果想要灵活指定父类T的类型，子类也需要变成类模板
// template<class T1,class T2>
// class Son2:public Father<T1>{
//     T2 p;
// };

// int main(){
//     Son2<int,char> s;//父类的T以int继承，子类中的p是char
// }




// //类模板对象做函数参数
// template<class T1,class T2>
// class Person{
//     public:
//     Person(T1 name,T2 age){
//         this->name=name;
//         this->age=age;
//     }
//     void show(){
//         cout<<this->name<<"  "<<this->age<<endl;
//     }
//     T1 name;
//     T2 age;
// };

// //1.指定传入参数类型
// void Print1(Person<string,int> &p){
//     p.show();
// }

// //2.参数模板化
// template<class T1,class T2>
// void Print2(Person<T1,T2> &p){//函数模板，自动推导了
//     p.show();
//     cout<<"T1:"<<typeid(T1).name()<<endl;//string
//     cout<<"T2:"<<typeid(T2).name()<<endl;//int
// }

// //3.整个类模板化
// template<class T>
// void Print3(T &p){//相当于Person<string,int>变成T
//     p.show(); 
// }


// void test1(){
//     Person<string,int> p("张三",21);
//     Print1(p);
//     Print2(p);
//     Print3(p);
// }

// int main(){
//     test1();
//     return 0;
// }









// //类模板中成员函数的创建时机
// class Person1{
//     public:
//     void show1(){}
// };
// class Person2{
//     public:
//     void show2(){}
// };

// template<class T>
// class Test{
//     public:
//     T a;
//     void func1(){
//         a.show1();
//     }
//     void func2(){
//         a.show2();
//     }
// };

// int main(){
//     Test<Person1> C;
//     C.func1();
//     // C.func2();
//     return 0;
// }






// //类模板和函数模板区别
// template<class NameType,class AgeType=int>
// class Person{
//     public:
//     Person(NameType name,AgeType age){
//         this->name=name;
//         this->age=age;
//     }
//     void show(){
//         cout<<this->name<<"   "<<this->age<<endl;
//     }
//     NameType name;
//     AgeType age;
// };

// //类模板没有自动类型推导
// void test1(){
//     Person p1("ghl",20);//报错
//     Person<string,int> p2("ghl",20);
// }

// //类模板在模板参数列表中可以有默认参数
// void test2(){
//     Person<string> p("ghl",20);
// }

// int main(){
//     test1();
//     test2();
// }



// //类模板
// template<class NameType,class AgeType>//光一个T类型肯定不够
// class Person{
//     public:
//     Person(NameType name,AgeType age){
//         this->name=name;
//         this->age=age;
//     }
//     void show(){
//         cout<<this->name<<"   "<<this->age<<endl;
//     }
//     NameType name;
//     AgeType age;
// };

// void test(){
//     Person<string,int> p1("ghl",20);//把类型参数化了，像传参数一样
//     p1.show();
// }

// int main(){
//     test();
//     return 0;
// }

// //模板并非万能，自定义数据类与STL容器，需要用具体化的方式做特殊实现
// class Person{
//     public:
//     Person(string name,int age){
//         this->name=name;this->age=age;
//     }
//     string name;
//     int age;
// };

// template<typename T>
// bool Compare(T &a,T &b){
//     return a==b;
// }
// //具体化
// template<> bool Compare(Person &a,Person &b){
//     return a.name==b.name;
// }

// void test1(){
//     Person p1("张三",12);
//     Person p2("张三",166);
//     if(Compare(p1,p2)){
//         cout<<"相等"<<endl;
//     }
//     else{
//         cout<<"不相等"<<endl;
//     }
// }

// int main(){
//     test1();
//     return 0;
// }





// //普通函数和函数模板的调用
// template<typename T>
// void Print(T a,T b){
//     cout<<"调用函数模板1"<<endl;
// }
// template<typename T>
// void Print(T a,T b,T c){
//     cout<<"调用函数模板2"<<endl;
// }
// void Print(int a,int b){
//     cout<<"调用普通函数"<<endl;
// }


// void test1(){
//     //优先调用普通
//     int a=10;int b=10;
//     Print(a,b);//普通

//     //空模板参数列表
//     Print<>(a,b);

//     //函数模板重载
//     Print(a,b,100);

//     //如果函数模板产生更好的匹配，优先调用
//     char c1='a';
//     char c2='b';
//     Print(c1,c2);//因为普通的需要强转
// }

// int main(){
//     test1();
//     return 0;
// }






// //普通函数与函数模板区别
// //普通函数 
// int commen_add(int a,int b){
//     return a+b;
// }

// //函数模板
// template<typename T>
// int template_add(T a,T b){
//     return a+b;
// }

// void test1(){
//     int a=10;
//     char b='b';//ASCII  a=97   b=98
//     cout<<commen_add(a,b)<<endl;//108

//     //自动类型推导
//     int n=template_add(a,b);
//     cout<<n<<endl;//到底转哪个编译器不知道

//     //显式指定类型
//     int m=template_add<int>(a,b);
//     cout<<m<<endl;
// }

// int main(){
//     test1();
//     return 0;
// }





// //数组排序案例
// template<typename T>
// void MySort(T arr[],int len){
//     for(int i=0;i<len;i++){
//         int max=i;
//         for(int j=i+1;j<len;j++){
//             if(arr[j]>arr[max]){
//                 max=j;
//             }
//         }
//         if(i!=max){
//             T temp=arr[max];
//             arr[max]=arr[i];
//             arr[i]=temp;
//         }
//     }
// }

// //打印模板
// template<typename T>
// void Printarr(T arr[],int len){
//     for(int i=0;i<len;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// } 



// int main(){
//     //测试char
//     char arrC[]="abefdc";
//     int n=sizeof(arrC)/sizeof(char);
//     MySort(arrC,n);
//     Printarr(arrC,n);
//     //测试int
//     int arrI[]={1,2,3,4,5,6,7,8,9};
//     int m=sizeof(arrI)/sizeof(int);
//     MySort(arrI,m);
//     Printarr(arrI,m);
//     return 0;
// }






// //函数模板注意事项

// //自动推导的话，必须推导出一致的数据类型才可以使用
// template<typename T>
// void func1(T &a,T &b){
    
// }

// void test1(){
//     int a=5;double b=1.2;
//     func1(a,b);//自动推导到不相同会报错
// }

// //模板必须要确认T的数据类型才可以使用
// template<typename T>
// void func2(){
    
// }

// void test2(){
//     func2();//即便是空实现也需要告诉他是什么
//     func2<int>();//随便给一个
// }






// //交换两个int
// void swapInt(int &a,int &b){
//     int temp=a;
//     a=b;
//     b=temp;
// }

// //交换两个double
// void swapDouble(double &a,double &b){
//     double temp=a;
//     a=b;
//     b=temp;
// }

// //有那么多数据类型，难道都要一个个写吗
// //所以使用函数模板
// template<typename T>
// void MySwap(T &a,T &b){
//     T temp=b;
//     b=a;
//     a=temp;
// }

// int main(){
//     int a=10;
//     int b=20;

//     //两种方式使用函数模板
//     MySwap(a,b);

//     MySwap<int>(a,b);

//     cout<<"a="<<a<<endl;
//     cout<<"b="<<b<<endl;
// }