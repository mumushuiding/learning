// ====================
// f0201 计算级数
// ====================
#include<iostream>
#include<cmath>
using namespace std;

int main(){
  double x;
  cin>>x;
  double sum=1.0;
  double t=x;
  int i=2;
  while(abs(t)>1e-8){ // 绝对值 
    sum+=t;
    t=(-1)*t*x/i;
    i++;
  }
  cout.precision(8);
  cout<<fixed<<sum<<endl;
}