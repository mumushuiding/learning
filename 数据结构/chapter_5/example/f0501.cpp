#include<iostream>
#include"compswap.h"

void sort(Item a[],int l,int r){
  for (int i=l;i<=r;i++){
    for(int j=i;j>l;j--){
      compswap(a[j-1],a[j]);
    }
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