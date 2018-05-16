#include <stdio.h>
#include <unistd.h>
int main(){
  int i = 0;
  for (i=0;i< 50;++i){
    printf("#");
    fflush(stdout);
    usleep(30000);
  }
  printf("\n");
  return 0;
}
