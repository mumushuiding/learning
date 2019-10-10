typedef struct node *link;
typedef int ListItem; // 表中元素类型
typedef ListItem* addr; // 表元素指针类型
typedef struct node {
  ListItem element;
  link left,right;
}Node;
typedef struct dlist *List;
typedef struct dlist {
  int n; // 表长
  link header; // 表首指针
  link curr; // 链表当前指针
} Dlist;
List ListInit(int size);
int ListEmpty(List L);
int ListLength(List L);
ListItem ListRetrieve(int k,List L);
int ListLocate(ListItem x,List L);
void ListInsert(int k,ListItem x,List L);
ListItem ListDelete(int k,List L);
void PrintList(List L);