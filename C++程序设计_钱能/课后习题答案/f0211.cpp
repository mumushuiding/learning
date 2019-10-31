// ========================
// f0211 小球落地问题
// ========================
#include<iostream>
using namespace std;
int main(){
  double sum=100;
  double h=50; // 第一次落地弹起高度
  for(int i=2;i<=10;i++){
    sum=sum+2*h;
    h=h/2; // 第i次落地弹起高度
  }
  cout<<"Distance="<<sum<<endl;
  cout<<"Bounce height="<<h<<endl;
}