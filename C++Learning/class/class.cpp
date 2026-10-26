#include<iostream>
#include<string>
using namespace std;

//+重载  operator+
class Person{
    public:
    int A;
    int B;

    //成员函数重载+
    Person operator+(Person& p){
        Person temp;
        temp.A=this->A+p.A;
        temp.B=this->B+p.B;
        return temp;
    }
};

//全局函数重载+
Person operator+(Person& p1,Person& p2){
    Person temp;
    temp.A=p1.A+p2.A;
    temp.B=p1.B+p2.B;
    return temp;
}

int main(){
    Person p1;
    p1.A=5;p1.B=10;
    Person p2;
    p2.A=5;p2.B=10;    /*对于全局函数来说本质是Person p3=operator+(p1,p2)*/
    Person p3=p1+p2;   /*对于成员函数来说本质是Person p3=p1.operator+(p2)*/
    cout<<p3.A<<"   "<<p3.B<<endl;//10与20
    return 0;
}





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
