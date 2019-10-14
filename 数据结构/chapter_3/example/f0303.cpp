// =============================
// 用指针实现队列
// =============================
#include<iostream>

typedef int QItem; // 队列元素类型
typedef struct qnode *qlink; // 队列结点指针类型
struct qnode{ // 队列结点
  QItem element;
  qlink next;
}Qnode;
qlink NewNode(){
  return (qlink)malloc(sizeof(Qnode));
}

typedef struct lque *Queue; // 队列指针
typedef struct lque{
  qlink front; // 队首指针
  qlink rear; // 队尾打针
}Lqueue;

Queue QueueInit(){
  // 给队列初始化空间
  Queue Q=(Queue)malloc(sizeof *Q);
  // 初始化参数
  Q->front=0;
  Q->rear=0;
  // 返回
  return Q;
}
int QueueEmpty(Queue Q){
  // 返回队首是否为空
  return Q->front==0;
}

QItem  QueueFirst(Queue Q){
  // 判断是否为空
  if(QueueEmpty(Q)) throw std::string("Queue is empty!");
  // 返回队首元素
  return Q->front->element;
}
QItem  QueueLast(Queue Q){
  // 判断是否为空
  if(QueueEmpty(Q)) throw std::string("Queue is empty!");
  // 返回队尾元素
  return Q->rear->element;
}
void EnterQueue(QItem x,Queue Q){
  // 创建一个新结点并赋值
  qlink p=NewNode();
  p->element=x;
  p->next=0;
  // 队尾插入新结点
  if(QueueEmpty(Q)){ // 队列空
    Q->front=p;
  } else { // 队列非空
    Q->rear->next=p;
  }
  // 更新队尾指针
  Q->rear=p;
}
QItem DeleteQueue(Queue Q){
  // 判断是否为空
  if (QueueEmpty(Q)) throw std::string("Queue is empty, delete fail");
  // 获取队首结点 p
  qlink p=Q->front;
  // 获取待删元素 x
  QItem x=p->element;
  // 修改队首结点指针
  Q->front=p->next;
  // 释放队首结点
  free(p);
  // 返回 x
  return x;
}

