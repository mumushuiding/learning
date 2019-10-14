// =================================
// 数组实现栈
// =================================
#include<iostream>
#define eq(A,B)(A==B)

typedef int StackItem;
typedef StackItem* addr;

typedef struct astack *Stack;
typedef struct astack{ // 栈结构
  int top; // 栈顶
  int maxtop; // 找空间上界
  StackItem *data; // 存储栈元素的数组

}Astack;
// StackInit 栈初始化
Stack StackInit(int size) {
  // 分配栈空间
  Stack S=(Stack)malloc(sizeof *S);
  // 栈中数组分配空间
  S->data=(StackItem *)malloc(sizeof(StackItem));
  // 设置空间上界
  S->maxtop=size;
  // 栈顶初始化
  S->top=-1;
  // 返回
  return S;
}
// StackEmpty 判断栈是否为空
int StackEmpty(Stack S){
  return S->top<0;
}
// StackFull 判断栈是否已满
int StackFull(Stack S) {
  return (S->top+1)==S->maxtop;
}
// StackTop 返回栈顶元素
StackItem StackTop(Stack S){
  // 判断是否为空
  if (StackEmpty(S)) throw std::string("stack is empty!");
  // 返回栈顶
  return S->data[S->top];
}
void Push(StackItem x,Stack S){
  // 判断是否栈满
  if(StackFull(S)) throw std::string("stack is full!");
  // 入栈
  S->data[++S->top]=x;
}
StackItem Pop(Stack S){
  // 判断是否为空
  if(StackEmpty(S)) throw std::string("stack is empty");
  // 出栈
  return S->data[S->top--];
}
void StackFreee(Stack S){
  free(S->data);
  free(S);
}

int main(){
  Stack s=StackInit(2);
  try{
      // 判断是否为空
    printf("stack is empty: %d\n", StackEmpty(s));
    // 入栈
    Push(1,s);
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