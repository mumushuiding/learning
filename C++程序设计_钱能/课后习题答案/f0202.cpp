// ====================
// f0202 计算 1!+2!+···+12!
// ====================

#include<iostream>
using namespace std;

int main(){
  double sum=1;
  double t=1;
  int i=2;
  while(i<=12){
    t*=i;
    sum+=t;
    i++;
  }
  cout<<sum<<endl;
}