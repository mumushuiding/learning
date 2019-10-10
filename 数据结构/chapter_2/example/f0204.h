typedef int ListItem; // 表中元素类型
typedef ListItem* addr; // 表元素指针类型
typedef struct snode * link;
typedef struct snode{
  ListItem element;
  int next;
}Snode;

typedef struct space *Space; // 模拟空间指针类型
typedef struct space{ // 模拟空间结构
  int num; // 可用数组空间大小
  int first; // 可用数组单元下标
  link node; // 可用空间数组 
}Simul;
typedef struct slist *List;
typedef struct slist{
  int first;
  Space s;
}Slist;
List ListInit(int size);
int ListEmpty(List L);
int ListLength(List L);
ListItem ListRetrieve(int k,List L);
int ListLocate(ListItem x,List L);
void ListInsert(int k,ListItem x,List L);
ListItem ListDelete(int k,List L);
void PrintList(List L);