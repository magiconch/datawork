#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
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

int main(int argc,char* argv[]){
  if (argc < 3){
    printf("Usage: %s [ip] [port]\n",argv[0]);
    return 1;
  }
  int listen_sock = startup(argv[1],atoi(argv[2]));
  while(1){
    int new_sock = accept(listen_sock,,sizeof(listen_sock))
      if (new_sock < 0){
        printf("")
      }
  }
  return 0;
}

