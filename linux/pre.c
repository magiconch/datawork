#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

//新线程创建成功后执行的函数
void* run(void* arg)
{
    while(1)
    {   
        printf("%s\n",(char*)arg);
        sleep(1);                                                                                                                     
    }   
}
int main()
{
    pthread_t tid;
    //新线程创建成功后去执行run指向的函数，主线程接着执行后面的代码
    pthread_create(&tid,NULL,run,"i am new pthread");//主线程创建新线程
    while(1)//主线程要执行的代码
    {   
        printf("i am main pthread\n");
        sleep(1);
    }   
    return 0;
}

