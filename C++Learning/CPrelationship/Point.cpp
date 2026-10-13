#include "Point.h"//自定义的头文件必须使用双引号

//源文件只留函数实现

void Point::setx(int sx){//这些现在是全局函数，而我们定义的它们是成员函数，所以需要Point::改变作用域
    x=sx;
}
void Point::sety(int sy){
    y=sy;
}
int Point::getx(){
    return x;
}
int Point::gety(){
    return y;
}