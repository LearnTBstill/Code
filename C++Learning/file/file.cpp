#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//二进制文件————读
class Person{
    public:
    char name[64];
    int age;
};//为了对号入座的接收

void test(){
    ifstream ifs("person.txt",ios::binary|ios::in);
    if(!ifs.is_open()){
        cout<<"打开失败"<<endl;
        return;
    }

    //开始读
    Person p;
    ifs.read((char*)&p,sizeof(Person));

    cout<<"姓名："<<p.name<<endl;
    cout<<"年龄："<<p.age<<endl;
    ifs.close();
}

int main(){
    test();
}

// //二进制文件————写
// class Person{
//     public:
//     char name[64];//这里不要用string，因为底层是C语言
//     int age;
// };

// void test(){
//     ofstream ofs("person.txt",ios::out | ios::binary);//不想用open可以直接使用它自带的构造函数
//     Person p={"张三",20};//列表初始化
//     ofs.write((const char*)&p,sizeof(Person));
//     ofs.close();
// }

// int main(){
//     test();
//     return 0;
// }


// //文本文件————读
// void test(){
//     ifstream ifs;
//     ifs.open("text.txt",ios::in);
//     if(!ifs.is_open()){
//         cout<<"打开失败"<<endl;
//         return;
//     }

//     //读数据方法一
//     char buf1[1000]={0};  //按"单词"读，遇到\n，Tab，空格会结束
//     while(ifs>>buf1){
//         cout<<buf1<<endl;
//     }   
//     //读数据方法二
//     char buf2[1000]={0};  //按"行"读，遇到\n结束
//     while(ifs.getline(buf2,sizeof(buf2))){
//         cout<<buf2<<endl;
//     }
//     //读数据方法三
//     string buf3;
//     while(getline(ifs,buf3)){ //全局的getline(读哪个,去哪里)
//         cout<<buf3<<endl;
//     }
//     //读数据方法四  不推荐这种
//     char c;
//     while((c=ifs.get())!=EOF){//一个一个字符去读
//         cout<<c;
//     }

//     ifs.close();     
// }

// int main(){
//     test();
// }



// //文本文件————写
// void test(){
//     //创建流对象
//     ofstream ofs;
//     //指定打开方式
//     ofs.open("text.txt",ios::out);
//     //写入
//     ofs<<"张三"<<endl;
//     ofs<<"李四"<<endl;
//     ofs<<"王五"<<endl;
//     //关闭
//     ofs.close();
// }              

// int main(){
//     test();
// }
