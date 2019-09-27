#include<iostream>
using namespace std;
void func();

int main(){
  func();
  func();

}
void func(){
  static int a=2;
  a+=2;
  cout<<a<<endl;
}