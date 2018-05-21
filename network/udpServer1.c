#include<stdio.h>                                                                                                                     
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>

int creat_sock(char* ip,char* port){
    int sock = socket(AF_INET,SOCK_DGRAM,0);
    if(sock < 0 ){
      printf("sock error\n");
      exit(2);
    }
    //这里创建了套接字的地址
    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(port));
    server.sin_port = inet_addr(ip);
    if (bind(sock,(struct sockaddr*)&server,sizeof(server)) < 0){
      printf("bind error\n");
      exit(2);
    }
    return sock; 
}

int main(int argc,char* argv[]){
  if (argc != 3){
    printf("Usage:%s[ip][port]",argv[0]);
    return 1;
  }
  char buf[1024] = {'\0'};
  struct sockaddr_in client;
  int sock = creat_sock(argv[1],argv[2]);
  while(1){
    socklen_t len = sizeof(client);
    ssize_t s = recvfrom(sock,buf,sizeof(buf)-1,0,(struct sockaddr*)&client,&len);
    if (s > 0){
      buf[s] = 0;
      printf("%s %d say# %s",inet_ntoa(client.sin_addr),ntohs(client.sin_port),buf);
    }
   sendto(sock,buf,strlen(buf),0,(struct sockaddr*)&client,len);  
  }
}
