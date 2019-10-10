#include<fstream>
#include<iostream>
#include"f0202.h"

typedef struct node *link;
typedef struct node{
  ListItem element;
  link next;
}Node;

link NewNode(){
  return (link)malloc(sizeof(Node));
}

typedef struct llist{
  link first,curr,last;
}Llist;

List ListInit(){
  List L=(List)malloc(sizeof*L);
  L->first=0;
  return L;
}
int ListEmpty(List L){
  return L->first==0;
}
int ListLength(List L){ // O(n)
  int length=0;
  link p=L->first;
  while(p){
    length++;
    p=p->next;
  }
  return length;
}
ListItem ListRetrieve(int k,List L){ // O(n)
  if(k<1) throw "k<1";
  link p=L->first;
  int i=1;
  while(i<k && p) {
    p=p->next;
    i++;
  }
  return p->element;
}
int ListLocate(ListItem x,List L) {
  int i=1;
  link p=L->first;
  while(p && x!=p->element){
    p=p->next;
    i++;
  }
  return p?i:0;
}
void ListInsert(int k,ListItem x,List L){
  if (k<0) throw "Error: k<0";
  link p=L->first;
  for (int i=1;i<k && p;i++){
    p=p->next;
  }
  link y=NewNode();
  y->element=x;
  if(k){
    y->next=p->next;
    p->next=y;
  } else{
    y->next=L->first;
    L->first=y;
  }
}
ListItem ListDelete(int k,List L){
  if(k<1||!L->first) throw std::string("k<1 or List is empty");
  link p=L->first;
  if (k==1){
    L->first=p->next;
  } else {
    link q=L->first;
    for (int i=1;i<k-1 && q;i++){ // 找到第k-1个
      q=q->next;
    }
    p=q->next; // 目标
    q->next=p->next;
  }
  ListItem x=p->element;
  free(p);
  return x;
}

void PrintList(List L){
  for(link p=L->first;p;p=p->next){
    printf("%d \n",p->element);
  }
}

int main(){
  try{
    List L;
    L=ListInit();
    ListInsert(0,1,L);
    ListInsert(1,2,L);
    ListInsert(2,3,L);
    ListInsert(1,5,L);
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