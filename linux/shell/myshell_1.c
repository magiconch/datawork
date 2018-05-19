#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void do_fork(char* arg[])
{

    pid_t pid = fork();
    if(pid == -1) 
    {   
        perror("fork error");
        exit(1);
 }
    else if(pid == 0)//子进程
    {   
        int ret = execvp(arg[0],arg);//使子进程执行exec函数，arg[0]表示要执行的命令，arg表示以何种方式执行
        if(ret == -1)
        {   
            printf("execv error\n");
            exit(1);
        }
    }
    else//父进程
    {   
        int st;
        int ret1 = wait(&st);//父进程等待
        if(ret1 == -1)
        {   
            printf("wait failed\n");
            exit(1);
        }
    
    }
}
int main(int argc,)
