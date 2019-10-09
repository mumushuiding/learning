#include<iostream>
using namespace std;

class Student{
  static int number; // number 为Student这个类独享的全局变量
};
int Student::number=0; // 静态数据成员在类外分配空间和初始化