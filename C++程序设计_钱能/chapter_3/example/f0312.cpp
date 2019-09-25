#include<iostream>
using namespace std;

int main(){
  float f=34.5;
  int* ip=(int*)(&f);
  cout<<"float address: "<<&f<<"=>"<<f<<endl;
  cout<<"  int address: "<<ip<<"=>"<<*ip<<endl; 

  int a=(int)f;
  cout<<a<<endl;

  int* sp=reinterpret_cast<int*>(123456);
  cout<<"  sp address:"<<sp<<"=>"<<*sp<<endl;

  int arr[6]={2,3.5};
  int* arrip=arr;
  cout<<"arrip address:"<<arrip<<"=>"<<*arrip<<endl;
}