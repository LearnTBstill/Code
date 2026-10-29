#include<iostream>
#include<string>
using namespace std;

//继承基本语法
//继承实现页面
class BasePage{
    public:
    void head(){
        cout<<"首页、公开课、登录、注册......(公共头部)"<<endl;
    }
    void footer(){
        cout<<"帮助中心、服务支持......(公共底部)"<<endl;
    }
    void left(){
        cout<<"Java、Python、C++......(公共分类列表)"<<endl;
    }
};

//Java页面
class Java:public BasePage{//让Java把BP的公共内容都继承过来
    public:
    void content(){
        cout<<"Jave学科视频"<<endl;
    }
};

//Python页面
class Python:public BasePage{
    public:
    void content(){
        cout<<"Python学科视频"<<endl;
    }
};

//C++页面
class CPP:public BasePage{
    public:
    void content(){
        cout<<"CPP学科视频"<<endl;
    }
};








// //函数调用运算符()重载          
// class MyPrint{
//     public:
//     void operator()(string p){//重载()实现打印
//         cout<<p<<endl;
//     }
// };
// void test1(){
//     MyPrint mp;
//     mp("Hello");//因为重载后使用方式很像函数调用，所以叫仿函数 
// }

// class MyAdd{
//     public:
//     int operator()(int a,int b){//重载()实现加法
//         return a+b;
//     }  
// };
// void test2(){
//     MyAdd md;
//     cout<<md(5,10)<<endl;
//     //匿名函数对象来实现
//     cout<<MyAdd()(5,10)<<endl;
// }

// int main(){
//     test1();
//     test2();
// }




// //关系运算符重载
// class Person{
//     public:
//     Person(string name,int age){
//         this->name=name;
//         this->age=age;
//     }
//     //==重载
//     bool operator==(Person& p){
//         if(this->name==p.name&&this->age==p.age){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
//     string name;
//     int age;
// };

// void test(){
//     Person p1("张三",18);
//     Person p2("张三",28);
//     if(p1==p2){
//         cout<<"p1,p2相等"<<endl;
//     }
//     else{
//         cout<<"p1,p2不相等"<<endl;
//     }
// }

// int main(){
//     test();
//     return 0;
// }




// //=重载
// class Person{
//     public:
//     int *A;
//     Person(int a){
//         A=new int(a);
//     }
//     ~Person(){
//         if(A!=NULL){
//             delete(A);
//         }
//         return;
//     }
//     //赋值重载
//     Person& operator=(Person& p){
//         //this.A=p.A;    编译器的浅拷贝
//         //要先判断是否有属性在堆区，如果有要先释放，不然拷贝之后原本的内存成孤儿了，内存泄漏
//         if(A!=NULL){
//             delete(A);
//             A=NULL;
//         }

//         //实现深拷贝
//         A=new int(*p.A);

//         return *this;
//     }
// };

// void test(){
//     Person p1(20);
//     Person p2(18);
//     p2=p1;
//     cout<<*p1.A<<endl;
//     cout<<*p2.A<<endl;

//     Person p3(15);
//     *p1.A=*p2.A=*p3.A;//这样写用的是内置的运算符
//     p1=p2=p3;//返回值必须是Person才能链式赋值
//     cout<<*p1.A<<"  "<<*p2.A<<"  "<<*p3.A<<endl;
// } 

// int main(){
//     test();
//     return 0;
// }


// //--重载
// class MyInt{
//     friend ostream& operator<<(ostream& cout,MyInt m);
//     public:
//     MyInt(){
//         A=5;
//     }
//     //--x
//     MyInt& operator--(){
//         this->A--;
//         return *this;    
//     }
//     //x--
//     MyInt operator--(int){
//         MyInt temp=*this;
//         this->A--;
//         return temp;
//     }
//     private:
//     int A;
// };

// ostream& operator<<(ostream& cout,MyInt m){
//     cout<<m.A;
//     return cout;
// }

// int main(){
//     MyInt m;
//     cout<<m--<<endl;//5
//     cout<<m<<endl;//4
//     cout<<--(--m)<<endl;//2
//     cout<<m<<endl;//2
//     return 0;
// }



// //++重载        实现自己定义的整型数据
// class MyInt{
//     friend ostream& operator<<(ostream& cout,MyInt m);
//     public:
//     MyInt(){
//         A=5;
//     }

//     //重载前置++
//     MyInt& operator++(){//引用返回是因为要对同一个数据操作
//         A++;            //为了实现链式调用所以必须返回MyInt
//         return *this;
//     }

//     //重载++后置
//     MyInt operator++(int){//用占位参数实现函数重载
//         MyInt temp=*this;
//         A++;
//         return temp;
//     }

//     private:
//     int A;
// };

// //重载<<
// ostream& operator<<(ostream& cout,MyInt m){//这块的m要值传递，因为++后置的重载返回的是值
//     cout<<m.A;
//     return cout;
// }

// int main(){
//     MyInt m;
//     cout<<m++<<endl;//5
//     cout<<m<<endl;//6
// }






// //左移运算符重载（也叫流插入运算符(cout)）
// class Person{
//     friend ostream& operator<<(ostream& out,Person& p);
//     public:
//     Person(int a,int b){
//         this->A=a;this->B=b;
//     }
//     private:
//     int A;
//     int B;

//     //成员函数                         不传参数的方式也不行，因为<<是双目运算符
//     void operator<<(ostream& cout){}//ostream类，这样就是p.operator<<(cout)，简写为p<<cout
// };

// //只能再全局函数重载<<
// ostream& operator<<(ostream& out,Person& p){//因为他不允许拷贝，只能有一个，所以绝不允许按值返回或传递
//     out<<"A="<<p.A<<endl;
//     out<<"B="<<p.B<<endl;
//     return out;
// }

// int main(){
//     Person p(5,10);
//     cout<<p<<endl;//要想实现链式调用需要返回一个cout，这样才能cout<<endl
// }







// //+重载  operator+
// class Person{
//     public:
//     int A;
//     int B;

//     //成员函数重载+
//     Person operator+(Person& p){
//         Person temp;
//         temp.A=this->A+p.A;
//         temp.B=this->B+p.B;
//         return temp;
//     }
// };

// //全局函数重载+
// Person operator+(Person& p1,Person& p2){
//     Person temp;
//     temp.A=p1.A+p2.A;
//     temp.B=p1.B+p2.B;
//     return temp;
// }

// int main(){
//     Person p1;
//     p1.A=5;p1.B=10;
//     Person p2;
//     p2.A=5;p2.B=10;    /*对于全局函数来说本质是Person p3=operator+(p1,p2)*/
//     Person p3=p1+p2;   /*对于成员函数来说本质是Person p3=p1.operator+(p2)*/
//     cout<<p3.A<<"   "<<p3.B<<endl;//10与20
//     return 0;
// }





// class cube{
//     public:
//     void seth(int h){
//         height=h;
//     }
//     void setl(int l){
//         length=l;
//     }
//     void setw(int w){
//         width=w;
//     }
//     int geth(){
//         return height;
//     }
//     int getw(){
//         return width;
//     }
//     int getl(){
//         return length;
//     }
//     int volume(){
//         return height*length*width;
//     }
//     int surface(){
//         return (height*length+height*width+width*length)*2;
//     }

//     bool equit(cube& c){
//         return c.height==height&&c.width==width&&c.length==length;
//     }

//     private:
//     int height=0;
//     int length=0;
//     int width=0;
// };

// bool equit(cube& c1,cube& c2){//别用值传递开销太大了
//     return c1.geth()==c2.geth()&&c1.getw()==c2.getw()&&c1.getl()==c2.getl();
// }

// int main(){
//     cube c1,c2;
//     c1.seth(10);c2.seth(5);
//     c1.setw(10);c2.setw(10);
//     c1.setl(10);c2.setl(10);
//     cout<<"c1周长为:"<<c1.surface()<<endl;
//     cout<<"c1面积为:"<<c1.volume()<<endl;

//     //在全局函数判断cube是否相等
//     if(equit(c1,c2)){
//         cout<<"全局函数判断为相等"<<endl;
//     }
//     else{
//         cout<<"全局函数判断为不相等"<<endl;
//     }

//     //在成员函数判断cube是否相等
//     if(c1.equit(c2)){
//         cout<<"成员函数判断为相等"<<endl;
//     }
//     else{
//         cout<<"成员函数判断为不相等"<<endl;
//     }
    
//     system("pause");
//     system("cls");
// }




// //成员属性设置私有
// class person{
//     public:
//     string getname(){//可以实现对name读
//         return name;
//     }
//     void setage(int Age){//可以实现对age写
//         age=Age;
//     }
//     private:
//     string name="aaa";//记得初始化，不然读乱码了
//     int age=20;
// };

// int main(){
//     person p1;
//     cout<<p1.getname()<<endl;
//     p1.setage(15);
//     cout<<p1.getage()<<endl;//不可读
// }





// class privilege{
//     public:
//     string name="zzz";

//     protected:
//     string car="a";
    
//     private:
//     int password=123123;

//     protected://函数的权限不影响类内访问,只不过如果不是public类外无法访问这个函数
//     void visit(){//类内都可以访问
//         name="aa";
//         car="bb";
//         password=123;
//     }
// };

// int main(){
//     privilege P1;
//     P1.name="cc";//公共权限，类外可以访问
//     P1.car="bb";//被保护权限，类外不可访问
//     P1.password=3333;//私有权限，类外不可访问
// }






// class student{
// public:
//     string name;
//     string num;

//     void assign(){
//         cout<<"请输入名称："<<endl;
//         cin>>name;
//         cout<<"请输入学号："<<endl;
//         cin>>num;
//     }
    
//     void show(){
//         cout<<"姓名为："<<name<<endl;
//         cout<<"学号为："<<num<<endl;
//     }
// };

// int main(){
//     student s1;
//     s1.assign();
//     s1.show();

//     student s2;
//     s2.assign();
//     s2.show();
// }










// const double pi=3.14;
// //创建一个圆类
// class Circle{
//     //访问权限
// public:
    
//     //属性（变量）
//     int r;

//     //行为（函数）
//     double getCircum(){
//         return 2*pi*r;
//     }
// };



// int main(){
//     //通过圆类来创建具体的对象    实例化(通过一个类创建对象)
//     Circle C1;
//     //给对象赋值
//     C1.r=5;
//     //调用行为
//     std::cout<<"圆的周长为："<<C1.getCircum()<<std::endl;
// }
