#include<iostream>
using namespace std;

int main() {
  int a=3,b=5;
  // int c= a*b + ++b; // 输出21
  // int c= ++b + a*b; // 输出24
  int c= ++b * (a+b); // 输出54
  cout<<c;
}