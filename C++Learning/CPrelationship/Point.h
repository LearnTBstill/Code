#pragma once //防止头文件重复包含
#include<iostream>
using namespace std;

//头文件中只用留声明

class Point{
    public:
    void setx(int sx);
    void sety(int sy);
    int getx();
    int gety();

    private:
    int x;
    int y;
};