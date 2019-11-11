// =======================
// f0302 输出各类型的字节长度和位长
// =======================
#include<iostream>
using namespace std;
int main(){
  long int a=1;
  int b=2;
  char c='A';
  float d=2.1;
  double e=2.20;
  long double f=3.33;
  cout<<"long int: "<<sizeof(a)<<" byte "<<8*sizeof(a)<<" bit"<<endl;
  cout<<"     int: "<<sizeof(b)<<" byte "<<8*sizeof(b)<<" bit"<<endl;
  cout<<"    char: "<<sizeof(c)<<" byte "<<8*sizeof(c)<<" bit"<<endl;
  cout<<"   float: "<<sizeof(d)<<" byte "<<8*sizeof(d)<<" bit"<<endl;
  cout<<"  double: "<<sizeof(e)<<" byte "<<8*sizeof(e)<<" bit"<<endl;
  cout<<"long double: "<<sizeof(f)<<" byte "<<8*sizeof(f)<<" bit"<<endl;
}