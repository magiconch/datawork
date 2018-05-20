#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<ctype.h>
char* arg[20] = {NULL};
void do_parse(char* buf){
  if (buf == NULL)
    return;
  if (isspace(*buf))
    ++buf;
  arg[1] = buf;
  int i = 2;
  while( *buf == '\n'){
    if (isspace(*buf))
      *buf = '\0';
    arg[i++] = buf + 1;
  } 
}

int main(){
  char buf1[1024] = {'\0'};
  char buf2[1024] = {'\0'};
  scanf("%[^  ]",buf1);
  scanf("%s",buf1);
  do_parse(buf2);
  for(int i=0;buf2[i]!='\n';++i){
    printf("%c",buf2[i]);
  }
  return 0;
}
