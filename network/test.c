int main(int argc,char* argv[])
{       
    if(argc != 3)//如果传入的参数不为3，打印用法说明
    {   
        printf("Usage:%s [ip][port]\n",argv[0]);
        return 1;
    }       
        
    //创建套接字文件
    int sock = socket(AF_INET,SOCK_DGRAM,0);
    if(sock < 0)//创建失败
    {   
        printf("sock error\n");
        return 2;
    }   
        
    //根据命令行参数来确定服务器端的套接字
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(atoi(argv[2]));
    socklen_t len = sizeof(server);
    //开始发送和接受数据
    char buf[128];
    struct sockaddr_in peer;
    while(1)
    {
        socklen_t len1 = sizeof(peer);
        printf("please enter#");
        fflush(stdout);
        buf[0] = 0;
        ssize_t s = read(0,buf,sizeof(buf) - 1);
        if(s > 0)
        {
            buf[s - 1] = 0;
            //发送请求
            sendto(sock,buf,strlen(buf),0,(struct sockaddr*)&server,len);
        }
        else if(s < 0)
        {
            break;
        }

        //接受服务器端传回的结果
        ssize_t ss = recvfrom(sock,buf,sizeof(buf) - 1,0,(struct sockaddr*)&peer,&len1);
        if(ss > 0)
        {
            buf[ss] = 0;
            printf("server# %s\n",buf);
        }
    }

    //当不再请求时，关闭套接字文件                                                                                                    
    close(sock);
    return 0;
}
