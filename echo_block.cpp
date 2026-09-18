#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
int main(){
    //创建监听套接字
    int listenfd = socket(PF_INET,SOCK_STREAM,0);
    //允许端口复用：程序重启时不用等内核释放端口
    int flag = 1;
    setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&flag,sizeof(flag));
    //绑定地址
    struct sockaddr_in addr;
    bzero(&addr,sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);//任意本机地址
    addr.sin_port = htons(9006);// htons:主机字节序转网络字节序
    bind(listenfd,(struct sockaddr *)&addr,sizeof(addr));
    //开始监听
    listen(listenfd,5);
    printf("listening on 9006...\n");
    //循环接受连接
    while(1){
        int connfd = accept(listenfd,NULL,NULL);
        printf("new client: %d\n",connfd);

        char buf[1024];
        while(1){
            int n = read(connfd,buf,sizeof(buf));
            if(n <= 0)break;
            write(connfd,buf,n);
        }
        close(connfd);
        printf("client %d closed\n",connfd);
    }
    close(listenfd);
    return 0;
}