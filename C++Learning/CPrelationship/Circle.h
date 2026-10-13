#pragma once
#include "Point.h"//需要用到Point
#include<iostream>
using namespace std;

class Circle{
    public:
    void setr(int sr);
    int getr();
    void setc(Point c);
    Point getc();

    private:
    Point center;
    int r;  
};