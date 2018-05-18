nclude<stdio.h>                                                                                                                     
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>

//该程序运行时的格式为：./a.out 192.168.3.95 8080
int main(int argc,char* argv[])
{
    if(argc != 3)//如果传入的参数不为3，则返回用法说明
    {
        printf("Usage:%s [ip][port]\n",argv[0]);
        return 1;
    }

    //打开套接字文件：套接字类型为IPv4类型，服务类型为UDP
    int sock = socket(AF_INET,SOCK_DGRAM,0);
    if(sock < 0)//打开失败
    {   
        printf("socket error\n");
        return 2;
    }   

    //将上述套接字文件和命令行指定的套接字进行绑定
    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_addr.s_addr = inet_addr(argv[1]);
    local.sin_port = htons(atoi(argv[2]));
    if(bind(sock,(struct sockaddr*)&local,sizeof(local)) < 0)//绑定失败
    {   
        printf("bind error\n");
        return 3;
    }   
    //开始接受和发送数据
    char buf[128];
    struct sockaddr_in client;
    while(1)
    {
        socklen_t len = sizeof(client);//每次接受到得客户端可能不同，所以，要在循环中求长度

        //接收来自客户端的请求
        ssize_t s = recvfrom(sock,buf,sizeof(buf) - 1,0,(struct sockaddr*)&client,&len);
        if(s > 0)
        {
            buf[s] = 0;
            printf("%s %d say# %s\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port),buf);
        }

        //处理请求并将结果发给客户端，这里请求的处理是原样发给客户端
        sendto(sock,buf,strlen(buf),0,(struct sockaddr*)&client,len);

    }
    return 0;
}             
