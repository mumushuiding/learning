typedef struct indlist *List;
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