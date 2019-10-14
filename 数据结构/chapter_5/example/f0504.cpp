// ===================
// 快速排序算法
// =================
#include<iostream>
#include"compswap.h"
int partition(int a[],int l,int r){
  // 设置基准元素v
  int v=a[r];
  // 设置左游标i,右游标j
  int i=l-1;
  int j=r;
  for(;;){
    // 从左往右判断是否小于 v,小于游标就右移,i自增
    while(less(a[++i],v));
    // 从右往左判断是否大于 v,是游标就左移,j自减,直至 j=l
    while(less(v,a[--j])) if(j==l) break;
    // i>=j 就 break
    if(i>=j) break; // 最后一次不交换
    // 交换i和j指向元素
    swap(a[i],a[j])
  }
  // 将基准r交换至左右部分的中点
  swap(a[i],a[r]);
  return i;
}
void sort(int a[],int l,int r){
  if (r<=l) return;
  int i=partition(a,l,r);
  sort(a,l,i-1);
  sort(a,i+1,r);
}
int main(){
  int size=6;
  int a[size]={7,9,8,3,5,4};
  sort(a,0,5);
  for (int i=0;i<size;i++){
    std::cout<<a[i]<<std::endl;
  }
}