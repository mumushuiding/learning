#include<iostream>
using namespace std;

int main(){
  int a[5];
  for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
  cout<<"size of a:"<< sizeof(a)<<endl;
  int b['a'];
  cout<<"size of b:"<< sizeof(b)<<endl;
  int c[true];
  c[4]=2;
  c[5]=3;
  c[7]=4;
  c[8]=5;
  c[9]=6;
  cout<<c[4]<<endl;
  cout<<c[5]<<endl;
  cout<<c[7]<<endl;
  cout<<c[8]<<endl;
  cout<<c[9]<<endl;
  cout<<"size of c:"<< sizeof(c)/sizeof(c[0])<<endl;
  c[0]=10;
  c[1]=11;
  cout<<c[0]<<endl;
  cout<<c[1]<<endl;


  int n=100;
  int d[n];
  cout<<"size of d:"<< sizeof(d)<<endl;

  int e[2]={10,11,};
  cout<<"size of e:"<< sizeof(e)<<endl;
}