#include<iostream>
#include"compswap.h"
#define RADIX 10
void countsort(int a[],int b[],int left,int right,int pow){
  // 计数器 cnt[RADIX] 清0
  int cnt[RADIX]={0};
  // 统计位为i的元素个数
  for(int i=left;i<=right;i++) cnt[a[i]/pow%RADIX]++;
  // 统计pow位小于或等于i的元素个数
  for(int i=1;i<RADIX;i++) cnt[i]+=cnt[i-1];
  // 将cnt[RADIX]中的数按排位写入数组b,每写一次相应计数器减1，这样重复的元素就可以往前排
  for(int i=right;i>=left;i--) b[--cnt[a[i]/pow%RADIX]]=a[i]; // 从后往前排是为了保证重复元素的排序同原来相同
  // 将排好序的数组b回写给a
  for(int i=left;i<=right;i++) a[i]=b[i-left];
}
void RadixSort(int a[],int left,int right){
  int maxv=0,pow=1;
  int * b=(int *)malloc(sizeof(int)*(right+1));
  // 找最大值，用于确定最高位
  for(int i=left;i<=right;i++) if(a[i]>maxv) maxv=a[i];
  // 从低位到高位按位计数排序
  while(maxv/pow>0){
    countsort(a,b,left,right,pow);// 按位计数排序
    pow*=RADIX;
  }
  free(b);
}
int main(){
  int size=11;
  int a[size]={12,7,9,8,3,5,12,4,12,34,12};
  RadixSort(a,0,size-1);
  for (int i=0;i<size;i++){
    std::cout<<a[i]<<std::endl;
  }
}