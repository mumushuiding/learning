#include<iostream>
#include"f0206.h"

link NewNode(){
  return (link)malloc(sizeof(Node));
}
List ListInit(){
  // 分配L空间
  List L=(List)malloc(sizeof *L);
  // 新建 header 结点
  link y=NewNode();
  y->left=y;
  y->right=y;
  L->header=y;
  L->n=0;
  return L;
}
ListItem ListRetrieve(int k,List L) {
  // 判断是否越界
  if(k<1||k>L->n) throw std::string("List index out of bounds!");
  // 是否获取的是尾元素
  if(k==L->n) {
    return L->header->left->element;
  }
  // 获取第一个元素
  link p=L->header->right;
  // 获取第k个元素
  for(int i=1;i<k;i++){
    p=p->right;
  }
  return p->element;
}
int ListLocate(ListItem x,List L){
  // 获取第一个元素
  int i=1;
  link p=L->header->right;
  L->header->element=x; // 结束标志,否则会无限循环
  // 遍历
  while(p->element!=x){
    p=p->right;
    i++;
  }
  return (p==L->header)?0:i;
}
void ListInsert(int k, ListItem x,List L){
  // 判断是否越界
  if (k<0||k>L->n) throw std::string("out of bonds!");
  // 获取 header 元素
  link p=L->header;
  // 获取第k个元素
  if(k==L->n) { // 判断是否是末尾插入
    p=p->left;
  } else{
    for(int i=0;i<k;i++) p=p->right;
  }
  // 新增节点
  link y=NewNode();
  y->element=x;
  y->left=p;
  y->right=p->right;
  // 修改插入位置前后结点的指针
  p->right->left=y;
  p->right=y;
  // 表长加1
  L->n++;

}

ListItem ListDelete(int k,List L){
  // 判断是否越界
  if (k<1||k>L->n) throw std::string("Out of Bounds!");
  // 获取 header 元素
  link p=L->header;
  //获取第k个元素
  if (k==L->n) { // 判断是否是末尾删除
    p=p->left;
  }else{
    for(int i=0;i<k;i++) {
      p=p->right;
    }
  }
  // 修改第k个元素左右元素的指针
  p->left->right=p->right;
  p->right->left=p->left;
  // 释放删除的元素
  ListItem x=p->element;
  free(p);
  // 更改表长
  L->n--;
  return x;
}