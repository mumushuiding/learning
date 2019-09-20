#include<iostream>
#include<cmath>
using namespace std;

int main(){
  double sum=1,item=1;
  int denom=1,sign=1;
  while(abs(item)>1e-6){
    denom+=2;
    sign *=-1;
    item=sign*1.0/denom;
    sum+=item;
  }
  cout<<"Pi = " <<fixed<<sum*4<<endl;
}