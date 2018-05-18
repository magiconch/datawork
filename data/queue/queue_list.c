#include <stdio.h>
#define MAX 100
typedef char ListType;
typedef struct QueueList{
  ListType element[MAX];
  size_t size;
}QueueList;
void ListInit(QueueList* list){
  if (list == NULL)
    return;
  list->size = 0;
  return;
}//初始化
void ListPush(QueueList* list,ListType value){
  if (list == NULL)
    return;
  list->element[list->size]= value;
  ++(list->size);
  return;
}//入队列
void ListPop(QueueList* list){
  if (list == NULL)
    return;
  if (list->size == 0)
    return;
  --(list->size);
  //int i =0;
  for (int i=0;i < list->size;++i){
    list->element[i] = list->element[i+1];
  }
  return;
}//出队列
ListType ListTop(QueueList* list){
  if (list == NULL)
    return '0';
  return list->element[0];
}//取队首元素
void TEST(){
  QueueList p;
  ListInit(&p);
  ListPush(&p,'1');
  ListPush(&p,'2');
  ListPush(&p,'3');
  ListPush(&p,'4');
  ListPush(&p,'5');
  ListPop(&p);
  printf("%c \n",ListTop(&p));
}
int main(){
  TEST();  
}

