#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void* do_this(void* arg){
  printf("%s%d\n",(char*)arg,pthread_self());
}

int main(){
  pthread_t tid;
  printf("I am main my id is:%d\n",pthread_self());
  pthread_create(&tid,NULL,do_this,"I am new pthread my id is"); 
  printf("have a test%d\n",tid);
    sleep(1);
    return 0;
}
