#include<iostream>
#include"compswap.h"
int min(int a[],int i,int r){
  int mini=i;
  for(int j=i+1;j<=r;j++){
    if(less(a[j],a[mini])){
      mini=j;
    }
  }
  return mini;
}
void sort(int a[],int l, int r){
  for(int i=l;i<r;i++){
    int j=min(a,i,r);
    swap(a[j],a[i]);
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