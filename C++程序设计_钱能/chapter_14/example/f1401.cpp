#include<iostream>

template<typename T>
void swap(T& a,T& b){
  T temp=a;a=b;b=temp;
}
int main(){
  int a=5,b=6;
  swap(a,b);
  float c=7.1,d=72.8;
  swap(c,d);
  std::cout<<"a="<<a<<"  b="<<b;
  std::cout<<"c="<<c<<"  d="<<d;
}