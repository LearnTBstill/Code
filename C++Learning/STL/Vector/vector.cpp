#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

//vector预留空间
int main(){
    vector<int> v;
    int num=0;//统计开辟次数
    int *p=NULL;
    for(int i=0;i<100000;i++){
        v.push_back(i);
        if(p!=&v[0]){
            p=&v[0];
            num++;
        }
    }
    cout<<num<<endl;//开辟了18次

    vector<int>v2;
    v2.reserve(100000);
    num=0;
    p=NULL;
    for(int i=0;i<100000;i++){
        v2.push_back(i);
        if(p!=&v2[0]){
            p=&v2[0];
            num++;
        }
    }
    cout<<num<<endl;//开辟了1次
}












// void PrintV(vector<int>& v){
//     for(vector<int>::iterator ite=v.begin();ite!=v.end();ite++){
//         cout<<*ite<<"   ";
//     }
//     cout<<endl;
// }
// //vector互换容器
// //基本使用
// void test1(){
//     vector<int> v1;
//     for(int i=0;i<10;i++){
//         v1.push_back(i);
//     }
//     PrintV(v1);//v1容器0~9
//     vector<int> v2;
//     for(int i=10;i>0;i--){
//         v2.push_back(i);
//     }
//     PrintV(v2);//v2容器10~1

//     //交换swap
//     v1.swap(v2);
//     PrintV(v1);//v1容器10~1
//     PrintV(v2);//v2容器0~9
// }

// //实际用途
// void test2(){
//     vector<int> v;
//     for(int i=0;i<100000;i++){
//         v.push_back(i);
//     }
//     cout<<v.capacity()<<endl;//v的容量  131072
//     cout<<v.size()<<endl;    //v的大小  100000

//     v.resize(3);
//     cout<<v.capacity()<<endl;//v的容量  131072
//     cout<<v.size()<<endl;    //v的大小  3

//     vector<int>(v).swap(v);
//     cout<<v.capacity()<<endl;//v的容量  3
//     cout<<v.size()<<endl;    //v的大小  3
// }

// int main(){
//     // test1();
//     test2();
//     return 0;
// }






// //vector数据存取
// int main(){
//     vector<int> v1;
//     for(int i=0;i<10;i++){
//         v1.push_back(i);
//     }

//     //operator[]访问
//     for(int i=0;i<v1.size();i++){
//         cout<<v1[i]<<"   ";
//     }
//     cout<<endl;

//     //at访问
//     for(int i=0;i<v1.size();i++){
//         cout<<v1.at(i)<<"   ";
//     }
//     cout<<endl;

//     //获取首元素
//     cout<<v1.front()<<endl;
    
//     //获取最后一个元素
//     cout<<v1.back()<<endl;
// }










// //vector插入删除
// int main(){
//     //尾插
//     vector<int> v1;
//     v1.push_back(10);v1.push_back(20);v1.push_back(30);v1.push_back(40);v1.push_back(50);
//     //尾删
//     v1.pop_back();//无返回值

//     //插入
//     v1.insert(v1.begin(),5);        //insert(const_iterator pos,elem); 迭代器指向位置pos插入elem
//     v1.insert(v1.begin(),2,5);      //insert(const_iterator pos,int n,elem); 迭代器指向位置pos插入n个elem

//     //删除
//     v1.erase(v1.begin());           //erase(const_iterator pos); 删除迭代器指向的元素 
//     v1.erase(v1.begin(),v1.end()-1);//erase(const_iterator start,const_iterator end); 删除迭代器区间的元素

//     //清空
//     v1.clear();
// }








// void PrintV(vector<int>& v){
//     for(vector<int>::iterator ite=v.begin();ite!=v.end();ite++){
//             cout<<*ite<<"   ";
//         }
//         cout<<endl;
// }
// //vector容量和大小
// int main(){
//     vector<int> v1;
//     for(int i=0;i<10;i++){
//         v1.push_back(i);
//     }
//     PrintV(v1);

//     //empty()
//     if(v1.empty()){//false                          //返回值bool
//         cout<<"空"<<endl;
//     }
//     else{
//         cout<<"非空"<<endl;
//     }

//     //capacity()
//     cout<<v1.capacity()<<endl;//16                  //返回值int
//     //size()
//     cout<<v1.size()<<endl;//10                      //返回值int

//     //resize()重新指定大小
//     v1.resize(15);
//     PrintV(v1);//0到9然后00000
//     v1.resize(5);
//     PrintV(v1);//0到4
// }









// void PrintV(vector<int>& v){
//     for(vector<int>::iterator ite=v.begin();ite!=v.end();ite++){
//         cout<<*ite<<"   ";
//     }
//     cout<<endl;
// }
// //vector赋值
// int main(){
//     vector<int> v1;
//     for(int i=0;i<10;i++){
//         v1.push_back(i);
//     }
//     PrintV(v1);

//     //operator=赋值
//     vector<int> v2; 
//     v2=v1;                                  //vector& operator=(const vector<int>& v);
//     PrintV(v1); 

//     //assign赋值
//     vector<int> v3;
//     v3.assign(v1.begin(),v1.end());        //assign(beg,end); 将区间内数据拷贝
//     PrintV(v3); 

//     vector<int> v4;
//     v4.assign(10,100);                     //assign(n,elem); n个elem
//     PrintV(v4);
// }







// void Printv(vector<int>& v){
//     for(vector<int>::iterator ite=v.begin();ite!=v.end();ite++){
//         cout<<*ite<<"   ";
//     }
//     cout<<endl;
// }

// //vector构造函数
// int main(){
//     //默认构造
//     vector<int> v1;
//     for(int i=0;i<10;i++){
//         v1.push_back(i);
//     }
//     Printv(v1);
//     //区间来构造                                             //将[v.begin(),v.end())左闭右开区间中的元素拷贝
//     vector<int> v2(v1.begin(),v1.end());
//     Printv(v2);
//     //n个elem                                               //vector(n,elem);
//     vector<int> v3(10,100);
//     Printv(v3);
//     //拷贝构造
//     vector<int> v4(v3);
//     Printv(v4);
// }






// //vector容器嵌套容器
// int main(){
//     vector<vector<int>> v;
//     //创建小容器
//     vector<int> v1;vector<int> v2;vector<int> v3;
//     for(int i=0;i<4;i++){
//         v1.push_back(i+1);v2.push_back(i+2);v3.push_back(i+3);
//     }
//     //插入大容器
//     v.push_back(v1);v.push_back(v2);v.push_back(v3);
//     //遍历所有数据
//     for(vector<vector<int>>::iterator it=v.begin();it!=v.end();it++){
//         for(vector<int>::iterator ite=(*it).begin();ite!=(*it).end();ite++){
//             cout<<*ite<<"   ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }




// //vector存放自定义数据类型
// class Person{
//     public:
//     Person(string name,int age){
//         this->name=name;
//         this->age=age;
//     }
//     string name;
//     int age;
// };

// void test1(){
//     vector<Person> v;
//     Person p1("刘",21);Person p2("关",25);Person p3("张",27);
//     v.push_back(p1);v.push_back(p2);v.push_back(p3); 
//     //遍历
//     for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
//         cout<<(*it).name<<"  "<<it->age<<endl;//解it之后是Person
//     }
// }

// void test2(){
//     vector<Person*> v;//存放指针的数组
//     Person p1("刘",21);Person p2("关",25);Person p3("张",27);
//     v.push_back(&p1);v.push_back(&p2);v.push_back(&p3);
//     //遍历
//     for(vector<Person*>::iterator it=v.begin();it!=v.end();it++){
//         cout<<(*(*it)).name<<"   "<<(*it)->age<<endl;//*it是一个指针，再->
//     }
// }

// int main(){
//     test1();
//     test2();
//     return 0;
// }



//vector存放内置数据类型
// void Print(int val){
//     cout<<val<<endl;
// }

// int main(){
//     //创建vector
//     vector<int> v;
//     //追加数据
//     v.push_back(1);
//     v.push_back(2);
//     v.push_back(5);
//     //通过迭代器访问数据
//     vector<int>::iterator iteBegin=v.begin();//vector<int>作用域下的iterator(一个内部类)
//     vector<int>::iterator iteEnd=v.end();
//     //第一种遍历方式
//     while(iteBegin!=iteEnd){
//         cout<<*iteBegin<<endl;
//         iteBegin++;
//     }
//     //第二种遍历方式(常用)
//     for(vector<int>::iterator it=v.begin();it!=v.end();it++){
//         cout<<*it<<endl;
//     }
//     //第三种遍历方式(STL提供的遍历算法)
//     for_each(v.begin(),v.end(),Print);
// }