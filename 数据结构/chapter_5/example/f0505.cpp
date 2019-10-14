// ===================
// 随机快速排序算法
// =================
#include<iostream>
#include"compswap.h"

int partition(int a[], int left,int right){
  // 设置基准元素v
  int v=a[right];
  // 设置左右游标i,j
  int i=left-1;
  int j=right;
  for(;;){
    // 从左往右判断是否小于 v,小于i自增
    while(less(a[++i],v));
    // 从右往左判断是否大于v,大于j自减
    while(less(v,a[--j])) if(j==left) break;
    // 判断 i>=j,是就结束for
    if (i>=j) break;
    // 交换 i,j指向元素
    swap(a[i],a[j]);
  }
  // 交换 i和right元素
  swap(a[i],a[right]);
  // 返回基准元素索引 i
  return i;
}
int randomi(int left,int right){
  return left+(right-left)*(1.0*rand()/RAND_MAX);
}
int randompartition(int a[],int left,int right){
  // 生成left与right之间的随机数 i
  int i=randomi(left,right);
  // 交换 i 和 right 指向的元素
  swap(a[i],a[right]);
  // 返回数组划分
  return partition(a,left,right);
}
void sort(int a[],int left,int right){
  if(right<=left)return;
  int i=randompartition(a,left,right);
  sort(a,left,i-1);
  sort(a,i+1,right);
}
int main(){
  int size=6;
  int a[size]={7,9,8,3,5,4};
  sort(a,0,5);
  for (int i=0;i<size;i++){
    std::cout<<a[i]<<std::endl;
  }
}