#include<iostream>
using namespace std;

long gcd1(int a,int b){
  for (int temp;b;a=b,b=temp){
    temp=a%b;
  }
  return a;
}
long gcd2(int a,int b){
  int c=a%b;
  if(c==0){
    return b;
  }
  return gcd2(b,c);
}
int main(){
  cout<<"Please input two number:"<<endl;
  int a,b;
  cin>>a>>b;
  cout<<"The Greatest Common Divisor:"<<gcd2(a,b)<<endl;
}