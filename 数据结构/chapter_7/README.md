# 第7章 散列表

集合运算：
  * SetUnion(A,B) 并集运算
  * SetIntersection(A,B) 交集运算
  * SetDifference(A,B) 差集运算
  * SetAssign(A,B) 赋值运算
  * SetEqual(A,B) 判等
  * SetMember(x,S) 成员运算
  * SetInsert(x,S) 插入运算
  * SetDelete(x,S) 删除运算


掌握用位向量实现集合的方法:
  * 适用范围: 当集合A⊆{1,2,...,n}的子集,n是不大的整数时,可以用位向量来实现
  * 结构:

  ```
  typedef struct bitset *Set;
  typedef struct bitset{
    int setsize; // 集合大小
    int arraysize; // 位数组大小
    unsigned short *v; // 位数组
  }
  ```
  * 实现:
    * SetEqual(A,B) 判等：通过检测A,B的位向量来判定
    * SetUnion(A,B) 并集运算：通过A,B的位向量按位或实现
    * SetIntersection(A,B) 交集运算：通过A,B的位向量按位与实现
    * * SetDifference(A,B) 差集运算：先位与得交集，再位或去掉交集
    

掌握用链表实现集合的方法

掌握数组实现符号表的方法

理解开散列和闭散列的概念

掌握用开散列表实现符号表的方法

