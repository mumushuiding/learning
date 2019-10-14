#include<iostream>
class Exception{
public:
  virtual const std::string what()=0;
};
class IsEmpty:public Exception{
public:
  const std::string what(){
    return "Is Empty";
  }
};
class IsFull:public Exception{
public:
const std::string what(){
  return "Is Full";
}
};
// 定义队列元素
typedef int QItem;
// 定义循环数组队列
typedef struct aque *Queue;
typedef struct aque{
  int maxsize; // 循环数组大小
  int front; // 队首游标
  int rear; // 队尾游标
  QItem *queue; // 循环数组
}Aqueue;
// QueueInit 队列初始化
Queue QueueInit(int size){
  // 初始化队列
  Queue Q=(Queue)malloc(sizeof *Q);
  // 初始化队列参数
  Q->maxsize=size+1;
  Q->front=Q->rear=0;
  Q->queue=(QItem *)malloc(size*sizeof(QItem));  // 初始化循环数组
  // 返回队列
  return Q;
}
int QueueEmpty(Queue Q){
  // 检测队首游标和队尾游标是否重合,来判断队列是否为空
  return Q->rear==Q->front;
}
int QueueFull(Queue Q){
  // 队尾游标加一之后,判断队首游标front与队尾游标rear是否重合,来判断是否是满队列
  std::cout<<"check if is full: front="<<Q->front<<"  rear="<<Q->rear<<std::endl;
  return ((Q->rear+1)%Q->maxsize)==Q->front?1:0;
}
QItem QueueFirst(Queue Q){
  // 判断是否为空
  if (QueueEmpty(Q)) throw IsEmpty();
  // 返回队首元素
  return Q->queue[(Q->front+1)%Q->maxsize];
}
QItem QueueLast(Queue Q){
  // 判断是否为空
  if (QueueEmpty(Q)) throw IsEmpty();
  // 返回队尾元素
  return Q->queue[Q->rear];
}
void EnterQueue(QItem x,Queue Q){
  // 判断是否满队列
  if (QueueFull(Q)) throw IsFull();
  // 队尾游标加1
  Q->rear=(Q->rear+1)%Q->maxsize;
  // 添加新元素到数组
  Q->queue[Q->rear]=x;
}
QItem DeleteQueue(Queue Q){
  // 判断是否为空
  if(QueueEmpty(Q)) throw IsEmpty(); 
  // 队首游标加1
  Q->front=(Q->front+1)%Q->maxsize;
  // 获取队首元素 x
  return Q->queue[Q->front];
}
int main(){
  try
  {
    Queue Q=QueueInit(3);
    // QueueFirst(Q);
    EnterQueue(2,Q);
    std::cout<<"Last is "<<QueueLast(Q)<<std::endl;
    EnterQueue(3,Q);
    std::cout<<"Last is "<<QueueLast(Q)<<std::endl;
    EnterQueue(4,Q);
    std::cout<<"Last is "<<QueueLast(Q)<<std::endl;
    std::cout<<"delete  "<<DeleteQueue(Q)<<std::endl;
    std::cout<<"delete  "<<DeleteQueue(Q)<<std::endl;
    std::cout<<"delete  "<<DeleteQueue(Q)<<std::endl;
    std::cout<<"delete  "<<DeleteQueue(Q)<<std::endl;
  }
  catch(Exception& e)
  {
    std::cout << e.what() << '\n';
  }
  
  

}