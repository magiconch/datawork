#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<wait.h>

int main()
{
    pid_t pid = fork();
    if(pid < 0)
    {
      perror("fork error");
    }
    else if(pid == 0)//子进程输出AA
    {
        while(1)
        {
            printf("A");
            fflush(stdout);
            usleep(123456);
            printf("A ");                                                                                                             
            fflush(stdout);
            usleep(125455);
        }
    }
    else//父进程输出BB
    {
        while(1)
        {
            printf("B");
            fflush(stdout);
            usleep(123456);
            printf("B ");
            fflush(stdout);
            usleep(125455);
        }
        wait(NULL);
    }
    return 0;
}   

