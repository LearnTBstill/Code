#pragma once
#include<iostream>
#include<string>
using namespace std;


//自己的通用的数组类
template<class T>
class MyArray{                               //拷贝构造和=重载都要写，一个是初始化的时候一个是赋值的时候
    public:
    //构造函数
    MyArray(int Capacity){
        this->Capacity=Capacity;
        this->Size=0;
        this->AddressP=new T[this->Capacity];
    }
    //拷贝构造
    MyArray(const MyArray& arr){//深拷贝
        this->Capacity=arr.Capacity;
        this->Size=arr.Size;
        // this->AddressP=arr.AddressP;//这是默认的浅拷贝
        this->AddressP=new T[arr.Capacity];
        //将原数组数据拷贝
        for(int i=0;i<this->Size;i++){
            this->AddressP[i]=arr.AddressP[i];
        }
    }
    //析构函数
    ~MyArray(){
        if(this->AddressP!=NULL)
        delete[] this->AddressP;
        this->AddressP=NULL;
    }
    //operator=防止浅拷贝
    MyArray& operator=(const MyArray& arr){//const理解为一个只读契约
        if(this==&arr){//防止自赋值
            return *this;
        }
        if(this->AddressP!=NULL){//先判断原先是否有堆区数据
            delete[] this->AddressP;
            this->AddressP=NULL;
            this->Capacity=0;
            this->Size=0;
        }
        this->AddressP=new T[arr.Capacity];
        for(int i=0;i<arr.Size;i++){
            this->AddressP[i]=arr.AddressP[i];
        }
        this->Capacity=arr.Capacity;
        this->Size=arr.Size;
        return *this; 
    }
    //尾插
    void Push_back(const T& value){
        if(this->Size==this->Capacity){
            cout<<"满了"<<endl;
            return;
        }
        this->AddressP[this->Size]=value;
        this->Size++; 
    }
    //尾删法
    void delete_back(){
        if(this->Size<=0){
            cout<<"空了"<<endl;
        }
        this->Size--;//逻辑上的
    }
    //通过下标访问          MyArray并不是自带的数组
    T& operator[](int index){
        return this->AddressP[index];
    }
    //返回数组容量
    int rC(){
        return this->Capacity;
    }
    //返回数组大小
    int rS(){
        return this->Size;
    }

    private:
    T* AddressP;//指向堆区开辟的数组
    int Capacity;//数组容量
    int Size;//数组元素个数
};


 