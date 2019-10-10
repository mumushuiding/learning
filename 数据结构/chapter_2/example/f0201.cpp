#include<iostream>
#include"f0201.h"
#define eq(A,B)(A==B)
void ItemShow(ListItem x) {
  printf("%d \n",x);
}
typedef struct alist{
  int n; // 表长
  int curr; //当前位置
  int maxsize; // 数组上界
  ListItem *table; // 记录表中元素的数组
}Alist;

List ListInit(int size) {
  List L=(List)malloc(sizeof*L);
  L->table=(ListItem*)malloc(size*sizeof(ListItem));
  L->maxsize=size;
  L->n=0;
  return L;
}
int ListEmpty(List L){
  return L->n==0;
}

int ListLength(List L){
  return L->n;
}

int ListLocate(ListItem x, List L){ // 时间复杂性为 O(n)
  for (int i=0;i<L->n;i++){
    if(L->table[i]==x) return ++i;
  }
  return 0;
}

ListItem ListRetrieve(int k,List L){
  if (k<1||k>L->n) exit(1);
  return L->table[k-1];
}
void ListInsert(int k,ListItem x,List L){
  if (k<0||k>L->n)exit(1);
  for(int i=L->n-1;i>=k;i--){
    L->table[i+1]=L->table[i+1]=L->table[i];
  }
  L->table[k]=x;
  L->n++;
}
ListItem ListDelete(int k,List L){
  if(k<1||k>L->n) exit(1);
  printf("delete number %d\n",k);
  ListItem x=L->table[k-1];
  for(int i=k;i<L->n;i++){
    L->table[i-1]=L->table[i];
  }
  L->n--;
  return x;
}
void PrintList(List L){
  for (int i=0;i<L->n;i++){
    ItemShow(L->table[i]);
  }
}
void ListFree(List L){
  free(L->table);
  free(L);
}
int main() {
  List L;
  L=ListInit(8);
  ListInsert(0,1,L);
  ListInsert(1,2,L);
  ListInsert(2,3,L);
  ListInsert(1,5,L);
  printf("length: %d\n",ListLength(L));
  ListDelete(2,L);
  printf("length: %d\n",ListLength(L));
  PrintList(L);
  ListFree(L);
}

