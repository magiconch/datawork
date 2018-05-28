#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  pid_t pid = fork();
  if (pid == -1){
    perror("fork error\n");
    exit(1);
  }else if (pid > 0){//父进程
    printf("father:pid = %d,ppid = %d\n",getpid(),getppid());
    sleep(1);
  }else{
    printf("child:pid = %d,ppid = %d\n",getpid(),getppid());
  }
  return 0;
}
//为什么fork会有两个返回值
//因为创建了两个进程
