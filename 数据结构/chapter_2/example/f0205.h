typedef struct clist *List;
typedef struct node *link;
typedef struct node{
  ListItem element;
  link next;
}Node;
typedef struct clist{ // 单循环链表
  int n; // 表长
  link last; // 链表末尾指针
}Clist;
typedef int ListItem; // 表中元素类型
typedef ListItem* addr; // 表元素指针类型
List ListInit(int size);
int ListEmpty(List L);
int ListLength(List L);
ListItem ListRetrieve(int k,List L);
int ListLocate(ListItem x,List L);
void ListInsert(int k,ListItem x,List L);
ListItem ListDelete(int k,List L);
void PrintList(List L);