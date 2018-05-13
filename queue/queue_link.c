#include<stdio.h>
#include<stdlib.h>
//链式队列
typedef char QueueType;
typedef struct Queue{
	QueueType data;
  struct Queue* next;
  struct Queue* end;
}Queue;


void QueueInit(Queue* head){//对栈进行初始化
  if (head == NULL)
    return;
  head->next = NULL;
  head->end = NULL;
  return;
}
void QueuePush(Queue* head,QueueType value){//入队列
  if (head == NULL)
    return;
  Queue* node = (Queue*)malloc(sizeof(Queue));
  node->next = head->next;
  head->next = node;
  node->data = value;
  return;
}

void QueuePop(Queue* head){
  if (head == NULL)
    return;
 Queue* to_delet = head->next;
 head->next = to_delet->next;
 free(to_delet);
 return;
}//出队列

QueueType QueueTop(Queue* head){
  if (head == NULL)
    return '-';
  if (head->next == NULL)
    return '-';

  return (head->next->data);
  
}//取队首元素
int main(){
  Queue head;
  QueueInit(&head);
  QueuePush(&head,'1');
  QueuePush(&head,'2');
  QueuePop(&head);
  printf("%c\n",QueueTop(&head));
}
