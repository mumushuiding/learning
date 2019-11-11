// =================
//  f0306 遍历数组的一种方法
// =================
#include<iostream>
using namespace std;
int main(){
  int sum[5]={0};
  int iArray[]={1,3,5,7};
  int size=sizeof(iArray)/sizeof(*iArray);
  int* iPtr=iArray;
  for(int n=0;n<size;n++){
    sum[0]+=iPtr[n]; // 索引方式
  }
  for(int n=0;n<size;n++){
    sum[1]+=*(iPtr+n); // 指针方式
  }
  for(int n=0;n<size;n++){
    // cout<<"iPtr="<<*iPtr<<"  *iPtr++="<<*iPtr++<<endl;
    sum[2]+=*iPtr ++; // 指针自增方式
  }
  for(int n=0;n<size;n++){
    sum[3]+=iArray[n]; // 
  }
  for(int n=0;n<size;n++){
    sum[4]+=*(iArray+n); // 
  }
  for(int n=0;n<5;n++){
    cout<<sum[n]<<",";
  }
}