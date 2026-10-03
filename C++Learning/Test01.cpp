#include<iostream>
using namespace std;
/*函数重载：可以让函数名相同，提高复用性 
  重载条件：1.同一作用域
           2.相同名字
           3.不同的参数类型or参数顺序or参数个数

  注意:编译器只看元素类型，你光交换名字是不可行的
       返回值不同不能作为重载条件
*/







// int test(int b,int){//占位参数，只写个元素类型    
//     return;         //想要调用它就需要传两个int
// }
// int test2(int a,int=10){//占位参数是可以设默认值的，这样的话调用它的时候就不用多传入int了
//     return;   
// }