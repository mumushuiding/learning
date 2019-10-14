#include<iostream>
#include"compswap.h"

void insert(int a[],int l,int i){
  // 待插入元素 x
  Item x=a[i];
  while(i>l && less(x,a[i-1])){
    a[i]=a[i-1]; // 如果大于x则后移一位
    i--;
  }
  a[i]=x;
}
void sort(int a[],int l,int r){
  for (int i=l+1;i<=r;i++){
    insert(a,l,i);
  }
}
int main(){
  int size=6;
  int a[size]={7,9,8,3,5,4};
  sort(a,0,5);

  for (int i=0;i<size;i++){
    std::cout<<a[i]<<std::endl;
  }
}