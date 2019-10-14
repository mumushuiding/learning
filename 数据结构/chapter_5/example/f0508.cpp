// ============================
//  基本合并排序算法
// ============================
#include<iostream>
#include"compswap.h"
typedef int Item;
void copy(int b[],int a[],int left,int right){
  for(int i=left;i<=right;i++) a[i]=b[i];
}
void mergeab(int a[],Item b[],int left,int medium,int right){
  // 设置数组a左右段游标i,j
  int i=left,j=medium+1;
  // 设置数组b游标k
  int k=left;
  // 取两段中较小元素放入数组b,较小元素所属段游标自增1,数组b游标自增1
  while((i<=medium) && (j<=right)){ // 左段或者右段已经遍历完成，就结束
    if(less(a[i],a[j])){
      b[k++]=a[i++]; // 左段值赋给b，且左游标i自增1; 
    } else {
      b[k++]=a[j++]; // 右游标自增1
    }
  }
  // 处理剩余元素
  if(i>medium){ // 将右半段剩余元素依次放入b
    for(i=j;i<=right;i++){
      b[k++]=a[i];
    }
  } else { // 将左半段剩余元素依次放入b
    for(;i<=medium;i++){
      b[k++]=a[i];
    }
  }
}
void msort(int a[],int left,int right){
  // 设置结束条件
  if(right<=left)return;
  // 取中点
  int medium=(right+left)/2;
  // 对左段排序
  msort(a,left,medium);
  // 对右段排序
  msort(a,medium+1,right);
  // 合并到数组b
  // int b[11];
  int *b=(int *)malloc(sizeof(int)*(right+1));
  mergeab(a,b,left,medium,right);
  // 复制回数组a
  copy(b,a,left,right);
  free(b);
}
void sort(int a[],int left,int right){
  msort(a,left,right);
}
int main(){
  int size=11;
  int a[size]={12,7,9,8,3,5,12,4,12,34,12};
  sort(a,0,size-1);
  for (int i=0;i<size;i++){
    std::cout<<a[i]<<std::endl;
  }
}