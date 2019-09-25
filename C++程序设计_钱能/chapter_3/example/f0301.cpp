#include<iostream>
using namespace std;

int main(){
  char* str="Hello"; // 有报错，但不影响结果
  cout<<*str<<endl; // *str指向首地址，所以返回首地址中的值
  cout<<str<<endl;

  string str1="Hello1";
  cout<<&str1<<endl; // 取地址值
}