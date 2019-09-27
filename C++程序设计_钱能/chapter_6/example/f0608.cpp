#include<iostream>
#include<vector>
#include<time.h>
#include<cmath>
using namespace std;
// 递归
int fibo1(int n) {
  return n<=1 ? n: fibo1(n-1)+fibo1(n-2);
}
// for 循环
int fibo2(int n) {
  int a=0,b=1,c;
  for (int i=2;i<=n;i++){
    c=a+b,a=b,b=c;
  }
  return c;
}
// vector + for 循环
int fibo3(int n) {
  vector<int> v(n+1,0);v[1]=1;
  for (int i=2;i<=n;i++){
    v[i]=v[i-1]+v[i-2];
  }
  return v[n];
}
// 数学公式方法  
int fibo4(int n) {
  return (pow((1+sqrt(5.0))/2,n)-pow((1-sqrt(5.0))/2,n))/sqrt(5.0);
}

int main(){
  int a;
  int times=100000;
  clock_t start=clock();
  // for(int i=0;i<times;i++){
  //   a=fibo1(35);
  // }
  // cout<<"Fibo1: "<<a<<"  time: "<<clock()-start<<"\n";

  start=clock();
  for(int i=0;i<times;i++){
    a=fibo2(35);
  }
  cout<<"Fibo2: "<<a<<"  time: "<<clock()-start<<"\n";

  start=clock();
  for(int i=0;i<times;i++){
    a=fibo3(35);
  }
  cout<<"Fibo3: "<<a<<"  time: "<<clock()-start<<"\n";

  start=clock();
  for(int i=0;i<times;i++){
    a=fibo4(35);
  }
  cout<<"Fibo4: "<<a<<"  time: "<<clock()-start<<"\n";
}