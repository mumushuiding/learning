#include<iostream>

typedef int TreeItem; // 树元素类型
typedef TreeItem* Treeaddr;

#define eq(A,B)(A=B)

typedef struct btnode *btlink; // 二叉树指针类型
struct btnode{ // 二叉树结点结构
  TreeItem element; // 二叉树标号（元素）
  btlink left;
  btlink right;
}Btnode;

btlink NewNode(){
  return (btlink)malloc(sizeof(Btnode));
}

// 二叉树指针类型
typedef struct binarytree *BinaryTree;
// 二叉树结构
struct binarytree{
  btlink root; // 树根
}BTree;
// BinaryInit 二叉树初始化
BinaryTree BinaryInit(){
  BinaryTree T=(BinaryTree)malloc(sizeof* T);
  T->root=0;
  return T;
}
// BinaryEmpty 是否为空
int BinaryEmpty(BinaryTree T){
  return T->root==0;
}
// Root 返回T的根结点标号
TreeItem Root(BinaryTree T){
  if(BinaryEmpty) throw std::string("binarytree is empty!");
  return T->root->element;
}
// MakeTree 构建新二叉树
void MakeTree(TreeItem x,BinaryTree T,BinaryTree L,BinaryTree R){
  T->root=NewNode();
  T->root->element=x;
  T->root->left=L->root;
  T->root->right=R->root;
  L->root=R->root=0;
}
// BreakTree 二叉树拆分，将T拆分为根节点标号元素、左子树L和右子树R
TreeItem BreakTree(BinaryTree T,BinaryTree L,BinaryTree R){
  if (!T->root) throw std::string("binarytree's root is empty ");
  TreeItem x=T->root->element;
  L->root=T->root->left;
  R->root=T->root->right;
  T->root=0;
  return x;
}
