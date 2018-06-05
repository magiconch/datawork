#include<stdio.h>
#include <unistd.h>
#include<pthread.h>

//睡眠排序

void* sleep_sort(void* pnum){
  printf("la");
  int num = *(unsigned int*)pnum;
  sleep(num);
  printf("%u ",num);
  return NULL;
}

int main(){
  unsigned int num[10] = {10,9,8,7,6,5,4,3,2,1};
  int len = 10;
  unsigned int* pnum = num;
  for (int i=0;i<len;++i){
    pthread_t tid;
    printf("%d",i);
    pthread_create(&tid,NULL,sleep_sort,pnum);
    ++pnum;
  }
  return 0;
}
