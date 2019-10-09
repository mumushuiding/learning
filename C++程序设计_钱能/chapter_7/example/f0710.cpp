#include<iostream>
using namespace std;

void print(int j);
int j=8;  

int main(){
  print(10);
}
void print(int j){
  cout<<"全局变量 j="<<::j<<endl;
  cout<<"函数变量 j="<<j<<endl;
}