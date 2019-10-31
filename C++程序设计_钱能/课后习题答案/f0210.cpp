// ========================
// f0210 母牛问题
// ========================
#include<iostream>
using namespace std;
int main(){
  int n,a=1,b=1,sum=1,temp;
  cout<<"please input a year:\n";
  cin>>n;
  for(int i=4;i<=n;i++){
    temp=a+sum;
    a=b;
    b=sum;
    sum=temp;
  }
  cout<<sum<<endl;
  return 0;
}

