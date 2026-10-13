#include "Circle.h"
#include "Point.h"
#include<iostream>
using namespace std;
//圆与点的关系
void judge(Point& p,Circle& c){
    int x1=(p.getx()-c.getc().getx())*(p.getx()-c.getc().getx());
    int x2=(p.gety()-c.getc().gety())*(p.gety()-c.getc().gety());
    int l=x1+x2;
    if(l==(c.getr())*(c.getr())){
        cout<<"点在圆上"<<endl;
    }
    else if(l>(c.getr())*(c.getr())){
        cout<<"点在圆外"<<endl;
    }
    else{
        cout<<"点在圆内"<<endl;
    }
}

int main(){
    Point p,cen;
    Circle c;
    p.setx(1);
    p.sety(-1);
    cen.setx(1);
    cen.sety(1);
    c.setc(cen);
    c.setr(3);
    judge(p,c);
}