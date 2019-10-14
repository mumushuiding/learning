// ==========================
// 三划分快速排序算法
// ==========================
#include<iostream>
#include"compswap.h"

void sort(int a[],int left,int right){
  // 设置 左、右、中左、中右游标i,j,p,q
  int i=left-1,j=right,p=left-1,q=right;
  // 设置基准元素v
  int v=a[right];
  // 设置结束条件
  if(right<=left)return;
  // 无限循环判断
  for(;;){
    // 从左->右，若小于基准,则i自增
    while(less(a[++i],v));
    // 从右->左，若大于基准，则j自减，直至j=left
    while(less(v,a[--j])) if(j==left) break;
    // 结束条件
    if(i>=j) break;
    // 交换不符合左右段条件的元素
    swap(a[i],a[j]);
    // 将左段中等于基准的元素交换至左段的左端
    if(eq(a[i],v)){
      p++;
      swap(a[p],a[i]);
    }
    // 将右段中等于基准的元素交换至右段的右端
    if(eq(a[j],v)){
      q--;
      swap(a[q],a[j]);
    }
  }
  // 将基准元素插入左右段中点
  swap(a[i],a[right]);
  // 左右游标更新
  j=i-1;i=i+1;
  // 将左段等于基准的元素交换至左段的右端
  for(int k=left;k<=p;k++,j--){
    swap(a[k],a[j]);
  }
  // 将右段等于基准的元素交换至右段的左端
  for(int k=right-1;k>=q;k--,i++){
    swap(a[k],a[i]);
  }
  // 分别对数组的左段和右段进行递归排序
  sort(a,left,j);
  sort(a,i,right);
}
int main(){
  int size=11;
  int a[size]={12,7,9,8,3,5,12,4,12,34,12};
  sort(a,0,size-1);
  for (int i=0;i<size;i++){
    std::cout<<a[i]<<std::endl;
  }
}