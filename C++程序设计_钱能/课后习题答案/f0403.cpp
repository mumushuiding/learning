// =================
//  f0403 组合公式
// =================
#include<iostream>
using namespace std;
int main(){
  unsigned int a=1,b=1;
  double s;
  for(int i=14;i<=18;i++){
    a*=i;
  }
  for(int i=2;i<=5;i++){
    b*=i;
  }
  s=a/b;
  cout<<"result="<<s<<endl;
}
