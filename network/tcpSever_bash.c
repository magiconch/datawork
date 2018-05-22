#include<string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
int server_sock(char* ip,int port){
    int sock = socket(AF_INET,SOCK_STREAM,0);
    if (sock < 0){
      printf("sock error\n");
      exit(2);
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);
    socklen_t len = sizeof(server);
    if (bind(sock,(struct sockaddr*)&server,len) < 0){
      printf("bind error\n");
      exit(3);
    }
    //创建套接字并绑定完成
    
    if (listen(sock,6) < 0){
      printf("listen error\n");
      exit(4);
    }
    return sock;
}

//客户端与服务器端建立连接之后的通信函数
void server_work(int client_sock,char* ip,int port){
  //连接成功时候
  
}

int main(int argc,char* argv[]){
  if (argc != 3){
    printf("Usage:[%s][ip][port]",argv[0]);
    return 1;
  }
//创建监听套接字
  int listen_sock = server_sock(argv[1],atoi(argv[2]));
  //对用户进行反馈
  printf("bind success\n");


  struct sockaddr_in client;
  while(1){
    socklen_t len = sizeof(client);
    int client_sock = accept(listen_sock,(struct sockaddr*)&client,
        &len);
    if(client_sock < 0){
      printf("accept error\n");
      continue;
    }
    char ip_buf[24] = {0};
    //转换IP地址
    inet_ntop(AF_INET,&client.sin_addr,ip_buf,sizeof(ip_buf));
    
  }
}
