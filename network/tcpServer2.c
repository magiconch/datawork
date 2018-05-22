#include<stdio.h>                                                                                                                     
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>



//得到监听套接字函数
int server_sock(char* ip,int port)
{
    //打开网卡文件，得到文件描述符
    int sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock < 0)
    {
        printf("socker error\n");
        exit(1);
    }

    struct sockaddr_in server;
    bzero(&server,sizeof(server));//使结构体server清零
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(port);
    socklen_t len = sizeof(server);

//    //一个服务器可能有多个网卡，一个网卡也可能绑定多个IP地址
//    //INADDR_ANY可以设置在所有IP地址上进行监听，
//    //直到客户端发来与指定的IP地址进行连接时，才确定使用哪个IP地址
//    server.sin_addr.s_addr = htonl(INADDR_ANY);
    //服务器需绑定固定的IP地址和端口号才能使客户端正确找到
    if(bind(sock,(struct sockaddr*)&server,len) < 0)                                                                                  
    {
        printf("bind error\n");
        exit(2);
    }

    //使sock处于监听状态，并且最多允许5个客户端处于连接等待状态，多于5的链接请求直接忽略
    if(listen(sock,5) < 0)
    {
        printf("listen error\n");
        exit(3);
    }

    return sock;//得到监听套接字
}

//客户端与服务器端建立连接之后的通信函数
void server_work(int client_sock,char* ip,int port)
{
    char buf[128];
    while(1)
    {
        buf[0] = 0;//清空字符串
        //服务器从客户端接受信息,如果客户端没有发来信息就阻塞等待
        ssize_t s = read(client_sock,buf,sizeof(buf) - 1);
        if(s > 0)
        {
            buf[s] = 0;
            printf("ip:%s,port:%d say# %s\n",ip,port,buf);
        }
        //如果读到的为0，说明此时客户端关闭了文件描述符，与之断开了连接
        //所以此时服务器应直接退出通信函数。
        else if(s == 0)
        {
            printf("ip:%s,port:%d quit\n",ip,port);
            break;
        }
        else
        {
            printf("read error\n");
            break;
        }

        //服务器端向客户端发送信息
        printf("please enter#");
        fflush(stdout);
        buf[0] = 0;
        int ss = read(0,buf,sizeof(buf) - 1);
        if(ss > 0)
        {
            buf[ss - 1] = 0; 
        }

        //将从键盘读到的信息写入客户端的网卡文件向其发送信息                                                                          
        write(client_sock,buf,strlen(buf));
        printf("waiting ...\n");
    }
}

//命令行输入的格式为：./a.out 192.168.3.95 8080
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
