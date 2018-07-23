#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>

int main(int argc,char* argv[]){
  if (argc != 3){
    printf("Usage:%s,[ip][port]\n",argv[0]);
    return 1;
  }

  int sock = socket(AF_INET,SOCK_DGRAM,0);
  if (sock < 0){
    perror("sock");
    return 2;
  }

  struct sockaddr_in local;
  local.sin_family = AF_INET;
  local.sin_addr.s_addr = inet_addr(argv[0]);
  local.sin_port = ntohs(atoi(argv[1]));

  if (bind(sock,(struct sockaddr*)&local,sizeof(local)) < 0){
      perror("bind");
      return 3;
  }

  char buf[128];
  
}
