#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void* do_this(void* arg){
  //线程需要执行的函数
  while(1){
    printf("%s",(char*)arg);
  //  printf("new pthread id:%d",pthread_self());
    sleep(1);
  }
  return NULL;
}

int main(){
  pthread_t tid;
  pthread_create(&tid,NULL,do_this,"I am a new pthred.\n");
  while(1){
    printf("I am a main pthred.\n"); 
    sleep(1);
  }
  return 0;
}
