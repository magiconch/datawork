#pragma once
#include <stdio.h>
#include <stdlib.h>
//栈和队列
#define MAX 100
typedef char StackType;
/*typedef char StackType;
typedef char TreeNodeType; 
typedef struct TreeNode { 
TreeNodeType data; 
struct TreeNode* lchild; 
struct TreeNode* rchild; 
} TreeNode; 
typedef TreeNode* QueueType;
*/
typedef char QueueType;
typedef struct Stack{
  StackType emm[MAX];
  size_t size;
}Stack;
//设计顺序栈和链表队列。以及其基本操作
//typedef char QueueType;
typedef struct Queue{
  QueueType data;
  struct Queue* next;
}Queue;
//结构体定义
void StackInit(Stack* stack);
void StackPush(Stack* stack,StackType value);
void StackPop(Stack* stack);
int StackTop(Stack* stack,StackType* value);
void QueueInit(Queue* queue);
void QueuePush(Queue* queue,QueueType value);
void QueuePop(Queue* queue);
int QueueTop(Queue* queue,QueueType* value);
