
#include <stdio.h>
#include <stdlib.h>
#include "stack_queue.h"
typedef char TreeNodeType; 

typedef struct TreeNode { 
TreeNodeType data; 
struct TreeNode* lchild; 
struct TreeNode* rchild; 
} TreeNode; 

void TreeInit(TreeNode** root){
  if(root == NULL)
    return;
  *root = NULL;
  return;
} 

void PreOrder(TreeNode* root){//树的前序遍历
  if (root == NULL)
    return;
  printf("%c ",root->data);
  PreOrder(root->lchild);
  PreOrder(root->rchild);
  //printf("%c ",pnode->data);
  return;
} 

void InOrder(TreeNode* root){
  if (root == NULL)
    return;
  InOrder(root->lchild);
  printf("%c ",root->data);
  InOrder(root->rchild);
  //printf("%c ",pnode->data);
  return;
} 

void PostOrder(TreeNode* root){
  if (root == NULL)
    return;
  PostOrder(root->lchild);
  PostOrder(root->rchild);
  printf("%c ",root->data);
  return;
}

void LevelOrder(TreeNode* root){//层序遍历
  if(root == NULL)
    return;

  //1.把根节点入队列
  Queue bin_queue;
  QueueInit(&bin_queue);
  QueuePush(&bin_queue,(QueueType)(root->data) );
  //2.取队首元素，然后把他们的左右节点入队列
  QueueType top;
  QueueTop(&bin_queue,&top);
  printf("%c ",top);
  while(1){
    QueueTop(&bin_queue,&top);
    printf("%c ",top);
    QueuePush(&bin_queue,root->lchild->data);
    QueuePush(&bin_queue,root->lchild->data);
  }
  
} 

/** 
* @brief 根据先序遍历结果(带有空节点标记), 
* 构造一棵树 
* 
* @param array[] 先序遍历的结果 
* @param size 数组中元素个数 
* @param null_node 数组中空节点的特殊标记. 
* 
* @return 
*/ 
TreeNode* TreeCreate(TreeNodeType array[], 
    size_t size, TreeNodeType null_node){
  //把数组中的每个元素添加到二叉树中
  if(*array == NULL)
    return NULL;
      
} 

void TreeDestroy(TreeNode** root){
  ;
} 

TreeNode* TreeClone(TreeNode* root); 

size_t TreeSize(TreeNode* root); 

/** 
* @brief 求一棵树的叶子节点个数 
* 
* @param root 
* 
* @return 
*/ 
size_t TreeLeafSize(TreeNode* root){

} 

/** 
* @brief 求一棵树第 K 层节点的个数 
* 
* @param root 
* 
* @return 
*/ 
size_t TreeKLevelSize(TreeNode* root, int K); 

size_t TreeHeight(TreeNode* root); 

TreeNode* TreeFind(TreeNode* root, TreeNodeType to_find); 

TreeNode* LChild(TreeNode* node); 

TreeNode* RChild(TreeNode* node); 

TreeNode* Parent(TreeNode* root, TreeNode* node); 

void PreOrderByLoop(TreeNode* root); 

void InOrderByLoop(TreeNode* root); 

void PostOrderByLoop(TreeNode* root); 

void TreeMirror(TreeNode* root); 

int IsCompleteTree(TreeNode* root);
