// ==========================
// 三数取中划分算法
// ==========================
#include<iostream>
#include"compswap.h"

int partition(int a[],int left,int right){
  // 设置基准元素v
  int v=a[right];
  // 设置左右游标i,j
  int i=left-1;
  int j=right;
  for(;;){
    // 从左->右判断是否小于基准,是游标i自增
    while(less(a[++i],v));
    // 从右->左判断是否大于基准,是游标j自减
    while(less(v,a[--j])) if (j==left) break;
    // 判断是否i>=j,是就不交换错误划分的元素
    if(i>=j) break;
    // 交换错误划分的元素 i和j分别指向的元素
    swap(a[i],a[j]);
  }
  // 将基准r指向的元素交换至中点
  swap(a[i],a[right]);
  return i;
}

void insertion(int a[],int left,int right){
  for(int i=left+1;i<=right;i++){
    int x=a[i]; // 待排序的元素
    while(i>left && less(x,a[i-1])) { // 同前一个元素相比
      a[i]=a[i-1]; //前一个若小于目标x,则向后移一位;
      i--; // 再比较前一位的前一位
    }
    a[i]=x; // 找到合适位置,将目标x值插入
  }
}
void qsort(int a[],int left,int right){
  if((right-left)<=5) return; 
  // 找中位数
  swap(a[(left+right)/2],a[right-1]);
  // 找最小
  compswap(a[left],a[right-1]);
  compswap(a[left],a[right]);
  // 找次小即中位数
  compswap(a[right-1],a[right]);
  int i=partition(a,left+1,right-1);
  qsort(a,left,i-1);
  qsort(a,i+1,right);
}
void sort(int a[],int left,int right){
  qsort(a,left,right);
  insertion(a,left,right);
}
int main(){
  int size=9;
  int a[size]={7,9,8,3,5,4,12,34,12};
  sort(a,0,8);
  for (int i=0;i<size;i++){
    std::cout<<a[i]<<std::endl;
  }
}