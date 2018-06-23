#include<ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<unistd.h>


//shell程序分为三部分
char* arg[20] = {NULL};
int count = 0;
//1.处理输入字符串，使其符合execpv的参数要求

void do_parse(char* buf){
  
  enum is_head{
    yes,no
  }is_head;//当遇到空格说明下一个是head
  is_head = yes;
  count = 0;
  for(int i=0;buf[i]!='\0';++i){
    if((!isspace(buf[i])) && is_head == yes){
      arg[count++] = buf + i;
      is_head = no;
    }else if (isspace(buf[i])){
      buf[i] = 0;
      is_head = yes;
    }
  }
  arg[count] = NULL;
}
//2.创建子进程，使shell程序运行在子进程上
void do_fork(){
  pid_t pid = fork();
  if(pid == -1){
    perror("fork error\n");
    exit(1);
  }else if (pid == 0){//子进程
    int ret = execvp(arg[0],arg);
    if(ret == -1){
      perror("execv error\n");
      exit(2);
    }
  }else{
    int st;
    int ret1 = wait(&st);
    if (ret1 == -1){
      printf("wait failed\n");
      exit(3);
    } //if(ret1 == -1) 
  }
} //do_fork
//ps：为什么shell程序要运行在子进程上？
//main函数负责处理协调
int main(){
  char buf[1024] = {0};
  while(1){
    printf("myshell# ");
    fgets(buf,sizeof(buf),stdin);
    do_parse(buf);
    do_fork();
   
  }
  return 0;
}
