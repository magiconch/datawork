#include <stdio.h>
#include <unistd.h>
int main(){
  char buf[50]={'#'};
  int i = 0;
  for (i=0;i< 50;++i){
    buf[i] = '\0';
    printf("[%d] %s",i*2,buf);
    fflush(stdout);
    usleep(30000);
    buf[i]= '#';
  }
  printf("\n");
  return 0;
}
