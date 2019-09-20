#include<iostream>
#include<cmath>
using namespace std;

int main(){
  cout<<"Please input a number:\n";
  int m;
  cin>>m;
  double sqrtm=sqrt(m*1.0);
  for(int i=2;i<=sqrtm;i++){
    if (m%i==0){
      cout<<m<<" not prime";
      return 1;
    }
  }
  cout<<m<<" prime\n";
}