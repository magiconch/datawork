#include<stdio.h>                                                                                                                     
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
  if (argc < 3){
    printf("Usage:%s [ip] [port]\n",argv[0]);
    return 1;
  }
  //argv[1] :ip
  //argv[2] :port
  int sock = socket(AF_INET,SOCK_DGRAM,0);
  if (sock < 0){
    printf("sock error\n");
    return 2;
  }
  struct sockaddr_in local;
  local.sin_family = AF_INET;
  local.sin_port = htons(atoi(argv[2]));
  local.sin_addr.s_addr = inet_addr(argv[1]);

  if (bind(sock,(struct sockaddr*)&local,sizeof(local)) < 0){
    printf("bind error\n");
    return 3;
  }


char buf[128];
struct sockaddr_in clint;
while(1){
  socklen_t len = sizeof(clint);
  ssize_t s = recvfrom(sock,buf,sizeof(buf) - 1,0,
      (struct sockaddr*)&clint,&len);
  if (s > 0){
    buf[s] = 0;
    printf("%s %d say# %s\n",inet_ntoa(clint.sin_addr),
        ntohs(clint.sin_port),buf);
  }


    sendto(sock,buf,strlen(buf),0,(struct sockaddr*)&clint,len);
}
  return 0;
}
