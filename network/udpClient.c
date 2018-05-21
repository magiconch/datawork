#include<stdio.h>                                                                                                                     
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>


int main(int argc,char* argv[]){
  if (argc != 3){
    printf("Usage:%s [ip][port]",argv[0]);
    return 1;
  }
  
  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(argv[1]);
  server.sin_port = htons(atoi(argv[2]));
  socklen_t len = sizeof(servre);
s
}
