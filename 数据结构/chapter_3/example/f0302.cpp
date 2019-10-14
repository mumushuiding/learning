// =================================
// 指针实现栈
// =================================
#include<iostream>
typedef int StackItem;
typedef struct snode *slink; // 栈结点指针类型
typedef struct snode{ // 栈结构
  StackItem element; // 栈元素
  slink next; // 下一结点指针
}StackNode;
// NewStackNode 新的结点
slink NewStackNode(){
  return (slink)malloc(sizeof(StackNode));
}
typedef struct lstack *Stack;
typedef struct lstack{
  slink top;
}Lstack;

Stack StackInit(){
  // 分配栈空间
  Stack S=(Stack)malloc(sizeof *S);
  // 初始化top指针
  S->top=0;
  return S;
}
int StackEmpty(Stack S){
  // 返回top指针
  return S->top==0;
}
StackItem StackTop(Stack S){
  // 判断是否为空
  if(StackEmpty(S)) throw std::string("stack is empty");
  // 返回栈顶
  return S->top->element;
}
void Push(StackItem x, Stack S){
  // 新建结节
  slink p=NewStackNode();
  p->element=x;
  p->next=S->top;
  // 设置新的栈顶
  S->top=p;

}
StackItem Pop(Stack S){
  // 判断是否为空
  if(StackEmpty(S)) throw std::string("stack is empty!");
  // 获取栈顶结点
  slink p=S->top;
  // 获取栈顶元素
  StackItem x=p->element;
  // 更新栈顶结点
  S->top=p->next;
  // 释放出栈结点
  free(p);
  return x;
}

int main(){
  Stack s=StackInit();
  try{
      // 判断是否为空
    printf("stack is empty: %d\n", StackEmpty(s));
    // 入栈
    Push(1,s);
    // 返回栈顶元素
    printf("stack top is:%d\n",StackTop(s));
    Push(2,s);
    // 返回栈顶元素
    printf("stack top is:%d\n",StackTop(s));
    // Push(3,s);
    // 返回栈顶元素
    // printf("stack top is:%d\n",StackTop(s));
    // 出栈
    printf("pop %d\n",Pop(s));
    printf("pop %d\n",Pop(s));
    printf("pop %d\n",Pop(s));
    printf("pop %d\n",Pop(s));
  }catch(std::string s){
    std::cout<<"err:"<<s<<std::endl;
  }
}