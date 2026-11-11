#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

//string子串
void test1(){
    string str="Hello";
    string Substr=str.substr(1,2);             //string substr(int pos=0,int n=pos)const;
    cout<<Substr<<endl;//el
}

//使用操作
void test2(){
    string email="zhangkaiwei@xx.com";
    //在邮箱中获取用户名信息
    string str;
    str=email.substr(0,email.find('@'));
    cout<<str<<endl;
}

int main(){
    test1();
    test2();
}







// //string插入删除
// int main(){
//     //插入
//     string str="Hello";
//     str.insert(1,"sss");                           //string& insert(int pos,const char*c);
//     cout<<str<<endl;//Hsssello

//     //删除
//     str.erase(1,6);                                //string& erase(int pos,int n);
//     cout<<str<<endl;//Ho
// }





// //string字符存取
// int main(){
//     string str="abcde";
//     //1.通过[]访问你单个字符                            //char& operator[](int n);
//     for(int i=0;i<str.size();i++){
//         cout<<str[i]<<"   ";
//     }
//     cout<<endl;
//     //2.通过at访问单个字符                             //char& at(int n);
//     for(int i=0;i<str.size();i++){
//         cout<<str.at(i)<<"   ";
//     }
//     cout<<endl;
//     //修改单个字符
//     str[0]='z';
//     cout<<str<<endl;//zbcde
//     str.at(1)='z';
//     cout<<str<<endl;//zzcde
// }





// //string比较
// int main(){
//     string str1="xello";
//     string str2="hello";
//     if(str1.compare(str2)==0){
//         cout<<"相等"<<endl;
//     }
//     else if(str1.compare(str2)==1){
//         cout<<"str1大于str2"<<endl;//走这个
//     }
//     else if(str1.compare(str2)==-1){
//         cout<<"str1小于str2"<<endl;
//     }
// }





// //string查找替换
// //1.查找
// void test1(){
//     //find
//     string str1="abcdefgde";
//     int pos=str1.find("de");                 //int find(const char* c,int pos=0) const;  
//     cout<<pos<<endl;//3
//     //rfind
//     pos=str1.rfind("de");                    
//     cout<<pos<<endl;//7
// }

// //2.替换
// void test2(){
//     string str2="abcd";
//     str2=str2.replace(1,2,"aasss");             //string& replace(int pos,int n,const char* c);
//     cout<<str2<<endl;//aaasssd
// }

// int main(){
//     test1();
//     test2();
// }





// //string拼接
// int main(){
//     //重载+=
//     string str1="我爱";                           //string& operator+=(const char* c)
//     str1+="玩游戏";
//     string str2="我爱";                           //string& operator+=(const string& s)
//     str2+=str1;
//     string str3="我爱";                           //string& operator+=(const char c)
//     str3+='你';
    
//     //函数方式拼接append
//     string str4="I love";
//     str4.append("play");                          //string& append(const char* c)
//     str4.append("game啊...",4);                   //string& append(const char* c,int n)      前n个拼接
//     cout<<str4<<endl;//I love playgame
//     string str5="Because ";
//     str5.append(str4);                            //string& append(const string& s)
//     cout<<str5<<endl;//Because I loveplaygame

//     string str6="Why?";
//     str6.append(str5,10,4);                       //string& append(const string& s,int n,int m)
//     cout<<str6<<endl;//Why?love
// }






// //string赋值
// int main(){
//     //重载=赋值
//     string str1;
//     str1="Hello World";              //string& operator=(const char* s)         char*赋值
//     string str2;
//     str2=str1;                       //string& operator=(const string& s)       字符串赋值
//     string str3;
//     str3='a';                        //string& operator=(char c)                char赋值(不常用)

//     //函数方式赋值                    
//     string str4;                     
//     str4.assign("Hello World");      //string& assign(const char* s)
//     string str5;
//     str5.assign("Hello World",5);    //string& assign(const char* s,int n)      前n个赋值
//     cout<<str5<<endl;//Hello
//     string str6;
//     str6.assign(str4);               //string& assign(const string& s)
//     string str7;
//     str7.assign(5,'a');              //string& assign(int n,char c)             n个c
//     cout<<str7<<endl;//aaaaa      
// }





// //string构造函数
// int main(){
//     string s1;//默认构造  

//     const char* str="hello world";
//     string s2(str);//有参构造

//     string s3(s2);//拷贝构造

//     string s4(5,'s');//sssss
// }