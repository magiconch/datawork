//#include <stdio.h>
//#include <stdlib.h>
#include "stack_queue.h"
//栈和队列
#define MAX 100
/*
typedef char StackType;
typedef struct Stack{
  StackType emm[MAX];
  size_t size;
}Stack;
//设计顺序栈和链表队列。以及其基本操作
typedef char QueueType;
typedef struct Queue{
  QueueType data;
  struct Queue* next;
}Queue;
//结构体定义

*/
//顺序栈的实现.
void StackInit(Stack* stack){
  if (stack == NULL)
    return;
  stack->emm[0] = 0;
  stack->size = 0;
  return;
} 
void StackPush(Stack* stack,StackType value){
  if (stack == NULL)
    return;
  stack->emm[stack->size] = value;
  ++(stack->size);
  return;
}
void StackPop(Stack* stack){
  if (stack ==  NULL)
    return;
  --(stack->size);
  return;
}
int StackTop(Stack* stack,StackType* value){
  if (stack == NULL)
    return 0;
  *value = (stack->emm[(stack->size)-1]);
  return 1;
}

//链表队列的实现.
void QueueInit(Queue* queue){
  if (queue == NULL)
    return;
  queue->next = NULL;
}

void QueuePush(Queue* queue,QueueType value){
  if (queue == NULL)
    return;
  Queue* newpo = (Queue*)malloc(sizeof(Queue));
  newpo->data = value;
  Queue* end = queue;
  while(end->next != NULL){
    end = end->next;
  }
  end->next = newpo;
  newpo->next = NULL;
  return;
}

void QueuePop(Queue* queue){
  if (queue == NULL)
    return; 
  Queue* to_delete = queue->next; 
  queue->next = to_delete->next; 
  free(to_delete); 
  return;
} 
int QueueTop(Queue* queue,QueueType* value){
  if (queue == NULL) 
    return 0; 
  value = &(queue->next->data); 
  return 1;
}

int main(){
  //printf("xxx\n");
  /*Stack p; 
  StackInit(&p);
  StackPush(&p,'1');
  StackPush(&p,'2');   
  StackPush(&p,'3');   
  StackPush(&p,'4');   
  StackPush(&p,'5');
  StackPop(&p);
  StackType p1;
  StackTop(&p,&p1);
  printf("%c ",p1);
 // printf("hahah\n");
  Queue w;
  QueueInit(&w);
  QueuePush(&w,'1');
  QueuePush(&w,'2');   
  QueuePush(&w,'3');   
  QueuePush(&w,'4');   
  QueuePush(&w,'5');
 // QueueTop(&w);
  QueueType w1;
  QueueTop(&w,&w1);
  printf("%c ",w1);*/
Stack ne;
  StackInit(&ne);
  StackPush(&ne,'1');
  StackType w1;
  StackTop(&ne,&w1);
  printf("lalala%c\n",w1);
  
}
