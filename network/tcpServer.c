#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>                                                                                                                
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>      
//AF_INET  IPV4
//流式套接字 SOCK_STREAM
//.tcpServer 127.0.0.1 8080
//band 函数
//listen监听
int startup(const char* ip , int port){
  int sock = socket(AF_INET,SOCK_STREAM,0);
  //填充套接字,目的是为了和绑定
  struct sockaddr_in local;
  local.sin_family = AF_INET;
  local.sin_addr.s_addr = inet_addr(ip);
  local.sin_port = htons(port);
  //开始绑定
  if (bind(sock,(struct sockaddr*)&local,sizeof(local)) < 0){
    printf("bind error!\n");
    exit(3);
  if (listen(sock,5) < 0){
    printf("listen error\n");
    exit(4);
  }
  //开始监听
  return sock;
}

int main(int argc,char* argv[])
{
    //如果命令行传入的参数个数不为3，弹出用法说明
    if(argc != 3)
    {
        printf("Usage:%s [ip][port]\n",argv[0]);
        return 1;
    }
    
    //打开网卡文件，将其绑定到指定的端口号和IP地址，并使其处于监听状态
    int listen_sock = server_sock(argv[1],atoi(argv[2]));//得到监听套接字
    printf("bind and listen success,wait accept...\n");

    //绑定并监听成功后，双方开始通信
    struct sockaddr_in client;//定义存放客户端套接字信息的结构体
    while(1)
    {
        socklen_t len = sizeof(client);//调用者指定存放结构体的缓冲区的大小
        //服务器端调用该函数阻塞等待客户端发来连接请求
        //如果连接建立成功之后，该函数接受客户端的链接请求
        int client_sock = accept(listen_sock,(struct sockaddr*)&client,&len);
        if(client_sock < 0)//接受失败
        {
            printf("accept error\n");                                                                                                 
            continue;
        }
        char ip_buf[24];
        ip_buf[0] = 0;
        //转换整型IP地址为字符串格式
        inet_ntop(AF_INET,&client.sin_addr,ip_buf,sizeof(ip_buf));

        //将从网络中接受的端口号转换为主机序列
        int port = ntohs(client.sin_port);
        printf("connect success, ip:[%s],port:[%d]\n",ip_buf,port);

        //此时，双方开始互发消息进行通信
        server_work(client_sock,ip_buf,port);
    }
    return 0;
}      
//AF_INET  IPV4
//流式套接字 SOCK_STREAM
//.tcpServer 127.0.0.1 8080
//band 函数
//listen监听
