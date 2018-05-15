#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
  int fd = open("file",O_RDONLY,0644);//0644指的是权限。
  if (fd < 0){
      perror("open!\n");
      return 1;
  }

  char buf[1024];
  const char* msg = "hello world\n";
  while(1){
    ssize_t s = read(fd,buf,strlen(msg));
    if (s > 0){
      printf("%s",buf);
    }
    else{
      break;
    }
  }
  close(fd);
  return 0;
}
