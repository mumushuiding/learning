#include<iostream>
using namespace std;

void print(int);
typedef void (*pp)(int);

int main(){
  pp pp=print;
}
void print(int a) {
  cout<<a<<endl;
}