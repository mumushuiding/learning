#include<iostream>
using namespace std;

typedef void (*MenuFun) ();
void f1(){cout<<"good!\n";}
void f2(){cout<<"better!\n";}

int main(){
  MenuFun fun[]={f1,f2}; // 本应是 fun[]={&f1,&f2},但是函数类型会自动转换为指针函数.
  fun[0]();
  fun[1]();
}