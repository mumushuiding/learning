#include<iostream>
using namespace std;

void print(int* b,int size);
int main(){
  int a[]={3,4,5,6};
  print(a,sizeof(a)/sizeof(a[0]));
}
void print(int* b,int size){
  cout<<b[size-1]<<endl;
}