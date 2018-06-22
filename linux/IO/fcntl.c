#include<sys/errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void SetNoBlock(int fd){
  int fl = fcntl(fd,F_GETFL);
  if (fl < 0){
    perror("fcntl");
    return;
  }

  fcntl(fd,F_SETFL,fl | O_NONBLOCK);
}

int main(){
  SetNoBlock(0);
  while(1){
   char buf[64] = {0};
   ssize_t fd = read(0,buf,sizeof(buf));
    if (fd > 0){
      printf("echo#%s",buf);
    }else if (fd == -1 && errno == EAGAIN){
      printf("stdin data is not ready\n");
      sleep(1);
    }else{
      printf("error!%d",fd);
    }
  }
  return 0;
}
