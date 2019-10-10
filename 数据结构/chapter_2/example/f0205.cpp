#include<iostream>
#include"f0205.h"

link NewNode(){
  return (link)malloc(sizeof(Node));
}
List ListInit(){
  List L=(List)malloc(sizeof * L);
  link y=NewNode();
  y->next=y;
  L->last=y;
  L->n=0;
  return L;
}
ListItem ListRetrieve(int k,List L){
  int i=1;
  if(k<1||k>L->n) throw std::string("Array index out of bounds!");
  link p=L->last->next->next; // 第二个元素
  while(i<k){
    p=p->next;
    i++;
  }
  return p->element;
}
int ListLocate(ListItem x,List L){
  int i=1;
  link p=L->last->next->next; // 第二个元素
  L->last->next->element=x; // 设置首元素的值
  while(p->element!=x){
    p=p->next;
    i++;
  }
  return (p==L->last->next)?0:i;
}
void ListInsert(int k,ListItem x, List L){
  if (k<0||k>L->n) throw std::string("Array index out of bouds!");
  link p=L->last->next; // 第一个元素
  for (int i=1;i<=k;i++) p=p->next; // 第k+1个元素
  link y=NewNode();
  y->element=x;
  y->next=p->next;
  p->next=y;
  if(k==L->n) L->last=y;
  L->n++;
}
ListItem ListDelete(int k,List L){
  if(k<1||k>L->n) exit(1);
  link q=L->last->next; // 首元素
  for(int i=0;i<k-1;i++) q=q->next; // 目标的前一个元素
  link p=q->next; // 目标
  q->next=p->next;
  if(k==L->n){ // 如果最后一个元素被删除
    L->last=q;
  }
  ListItem x=p->element;
  free(p);
  L->n--;
  return x;
}