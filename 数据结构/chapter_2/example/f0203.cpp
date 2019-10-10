#include<iostream>
#include"f0203.h"

typedef struct indlist{
  int n,curr;
  int maxsize;
  addr *table;
}Indlist;

addr NewNode(){
  return (addr)malloc(sizeof(addr));
}
List ListInit(int size){
  List L=(List)malloc(sizeof*L);
  L->n=0;
  L->maxsize=size;
  L->table=(addr *)malloc(size*sizeof(addr));
  return L;
}
int ListEmpty(List L){
  return L->n==0;
}
int ListLength(List L){
  return L->n;
}
ListItem ListRetrieve(int k,List L) {
  if(k<1 || k>L->n) throw std::string("Array index out of bounds!");
  return *L->table[k-1];
}
int ListLocate(ListItem x,List L){
  for(int i=0;i<L->n;i++){
    if (*L->table[i]==x) return ++i;
  }
  return 0;
}
void ListInsert(int k,ListItem x,List L) {
  if (k<0||k>L->n) throw std::string("Array index out of bounds!");
  for(int i=L->n-1;i>=k;i--){
    L->table[i+1]=L->table[i];
  }
  L->table[k]=NewNode();
  *L->table[k]=x;
  L->n++;
}
ListItem ListDelete(int k,List L){
  if (k<1||k>L->n) throw std::string("Array index out of bounds!");
  addr p=L->table[k-1];
  ListItem x=*p;
  for(int i=k;i<L->n;i++){
    L->table[i-1]=L->table[i];
  }
  L->n--;
  free(p);
  return x;
}
void PrintList(List L){
  for(int i=0;i<L->n;i++){
    printf("%d \n",*L->table[i]);
  }
}
int main(){
  try{
    List L;
    L=ListInit(5);
    ListInsert(0,1,L);
    ListInsert(1,2,L);
    ListInsert(2,3,L);
    ListInsert(3,5,L);
    printf("length: %d\n",ListLength(L));
    PrintList(L);
    ListDelete(2,L);
    printf("length: %d\n",ListLength(L));
    PrintList(L);
    ListDelete(0,L);
  } catch (std::string s){
    std::cout<<s<<std::endl;
  }
}