#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include<string.h>

int main(){
  int fd[2];
  if (pipe(fd) == -1){
    printf("pipe error\n");
    return 1;
  }
  char buf[200] = {0};
  while(fgets(buf,sizeof(buf),stdin)){//从标准输入中读取到buf
    if(write(fd[1],buf,sizeof(buf)) == -1){
      printf("write error\n");
      break;
    }
    if(read(fd[0],buf,sizeof(buf)) == -1){
      printf("read error\n");
      break;
    }
    if(write(1,buf,strlen(buf)) == -1){
        printf("print error\n");
        break;
    }
  }
  return 0;
}
