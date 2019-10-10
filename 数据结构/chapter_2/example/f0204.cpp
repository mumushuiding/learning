#include<iostream>
#include"f0204.h"

Space SpaceInit(int max) { // 创建一个可用数组最大长度为max的模拟空间结构
  Space s=(Space)malloc(sizeof *s);
  s->num=max;
  s->node=(link)malloc(max*(sizeof *s->node));
  for(int i=0;i<max-1;i++){
    s->node[i].next=i+1;
  }
  s->node[max-1].next=-1;
  s->first=0;
  return s;
}
int SpaceAllocate(Space s){ // 从当前可用数组空间分配一个数组单元
  int i=s->first;
  s->first=s->node[i].next;
  return i;
}
void SpaceDeallocate(int i,Space s) {
  s->node[i].next=s->first;
  s->first=i;
}

List ListInit(int size){
  List L=(List)malloc(sizeof *L);
  L->s=SpaceInit(size);
  L->first=-1;
  return L;
}
int ListLength(List L){
  int i=L->first,len=0;
  while(i!=1){
    len++;
    i=L->s->node[i].next;
  }
  return len;
}
ListItem ListRetrieve(int k,List L){
  int p,i=1;
  if (k<1)exit(1);
  p=L->first;
  while(i<k && p!=-1){
    p=L->s->node[p].next;
    i++;
  }
  return L->s->node[p].element;
}
int ListLocate(ListItem x,List L){
  int p,i=1;
  p=L->first;
  while(p!=-1 && L->s->node[p].element!=x){
    p=L->s->node[p].next;
    i++;
  }
  return (p>=0)?i:0;
}
void ListInsert(int k,ListItem x,List L){
  if(k<0) exit(1);
  int p=L->first;
  for(int i=1;i<k && p!=-1;i++) p=L->s->node[p].next;
  int y=SpaceAllocate(L->s);
  L->s->node[y].element=x;
  if(k){
    L->s->node[y].next=L->s->node[p].next;
    L->s->node[p].next=y;
  }else{
    L->s->node[y].next=L->first;
    L->first=y;
  }
}
ListItem ListDelete(int k, List L){
  if(k<1||L->first==-1)exit(1);
  int p=L->first;
  if(k==1){
    L->first=L->s->node[p].next;
  }else{
    int q=p;
    for (int i=1;i<k-1 && q!=-1;i++){
      q=L->s->node[q].next; // q 为删除元素的前一个的游标
    }
    p=L->s->node[q].next; // 删除元素的游标
    L->s->node[q].next=L->s->node[p].next; 
  }
  ListItem x=L->s->node[p].element;
  SpaceDeallocate(p,L->s);
  return x;
}