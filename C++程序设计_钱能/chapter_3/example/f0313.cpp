#include<iostream>
using namespace std;

int main(){
  const int a=78;
  int b=10;
  int c=18;

  const int* ip=&a; // const 修饰指向的实体类型-常量指针（pointer to constant）
  int* const cp=&b; // const 修饰指针*cp - 指针常量（constant pointer）
  int const* dp=&b; // 指针常量

  *ip=87; // 错： 常量指针不能修改指向的常量
  ip=&c; // ok: 常量指针可以修改指针值
  *cp=81; // ok: 指针常量可以修改指向的实体
  cp=&b; // 错： 指针常量不能修改指针值。
}

