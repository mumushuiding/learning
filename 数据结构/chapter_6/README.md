# 第六章 树

## 6.1 树的定义

<img src="./../img/数据结构-第四章 树的基本术语.png">

## 6.2 树的遍历

遍历： 对树中所有结点的系统的访问

遍历方法： 从树根出发，依逆时针方向沿树的外缘绕行
  * 前序遍历： 第一次经过的各个节点按时间次序列出
  * 中序遍历： 第一次经过的叶结点和第二次经过的内部结点按时列出
  * 后序遍历： 最后一次经过的结点按时序列出

## 6.3 树的表示法
  * 父结点数组表示法： 用一个一维数组存储每个结点的父结点。
  * 儿子链表表示法： 儿子表的表头存放于数组header中，表头指向儿子链表
  * 左儿子右兄弟（二叉树）表示法： 链表中结点的两个链域分别指向该结点的最左儿子和右邻兄弟。 

## 6.4 二叉树的基本概念

二叉树概念：
  * 度数不超过2
  * 结点有左右之分
  * 高度为h,至少有h+1个结点，至多有2^(h+1)-1个结点

## 6.6 二叉数的实现
  * 二叉树的顺序存储结构： 所有结点，按照一定的次序，存储到一片连续的存储单元中。
    * 对于结点 i 有如下关系：
      * i=1时，为根结点
      * 父结点为i/2(取下限)
      * 左儿子为2i
      * 右儿子为 2i+1
      * 左兄弟为i-1 (i为奇数)
      * 右兄弟为i+1 (i为偶数)
  * 二叉数的结点度表示: 所有结点依其后序列表排列，并附加0~3表示结点的状态,0为叶节点，1为只有一个左儿子，2为只有一个右儿子，3为有两个儿子。
  * 用指针实现二叉数
    * 指针类型： typedef struct btnode *btlink
    * 结点结构：

    ```


    ```
   * 新建结点：

   ```
   btlink NewNode() {
     return (btlink)malloc(sizeof(Btnode));
   }
   ```

   * 二叉树结构：
  
   ```
   typedef struct binarytree *BinaryTree;
   typedef struct binarytree{
     btlink root;// 树根
   }Btree;
   BinaryTree BinaryInit(){
     BinaryTree T=(BinaryTree)malloc(sizeof *T);
     T->root=0;
     return T;
   }
   ```
  * 线索二叉数：在指针实现二叉树时，添加左右线索标志leftThread、rightThread
    * 结点结构：

      ```
      struct tbtnode{
        TreeItem element;
        btlink left; // 左子树
        btlink right; // 右子树
        int leftThread; // 左线索标志,为0时指向左儿子结点,为1时指向前驱结点的左线索 
        int rightThread; // 右线索标志,为0时指向右儿子结点,为1时指向后继结点的右线索
      }ThreadedNode;
      ```
    * 左线索：
      * 为0时 left 指针指向左儿子
      * 为1时 left 指向前驱结点
    * 右线索：
      * 为0时 right 指向右儿子
      * 为1时 right 指向后继结点
  * 二叉搜索树：
    * 适用范围： 存储有序集，如字典
    * 结构:

      ```
      struct btnode{
        TreeItem element;
        btlink left; // 左子树
        btlink right; // 右子树
        btlink parent; // 父结点指针
      }Btnode;
      ```
    * 运算：
      * 插入运算 Insert(x,S): 找到一个空指针就插入
      * 删除运算 Delete(x,S)
        * 找到存储x的结点
        * 删除结点
          * 如果是叶节点，直接删除
          * 如果只有一个儿子结点，用儿子替代它
          * 如果有两个儿子结点，可以用结点的前驱或者后继结点替代它（替代之后按中序遍历，结点将按从小到大排列）
      * 前驱运算 Predecessor(x,S) 返回集合中小于x的最大元素 （中序遍历），搜索时间 O(logn)
      * 后继运算 Successor(x,S) 返回集合中大于x的最小元素 （中序遍历）, 搜索时间 O(logn)
      * 区间查询运算 Range(x,y,S) 返回集合S中界于x和y之间的所有元素组成的集合，搜索时间 O(logn)
    * 结构：结点标号、左子树、右子树、父结点
    * 性质：
      * 结点元素大于其左子树任一结点元素
      * 结点元素小于其右子树任一结点元素
  * 线段树：
    * 适用范围：用于解决与矩形相关的计算几何问题
    * 结构：

    ```
    struct stnode{
      int left; //标准线段左端
      int right;//标准线段右段
      int count;//正则覆盖计数
    }
    ```
  * 序列数：
    * 适用范围：用于解决与序列有关的计算问题
    * 结点类型定义：
    
    ```
    struct seqnode{
      int left;//标准子序列左端
      int right;//标准子序列右端
      int sum;//标准子序列和
      int min;//标准子序列最小值
      int max;//标准子序列最大值
    }Sqnode;
    ```


