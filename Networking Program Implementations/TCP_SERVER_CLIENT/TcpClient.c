#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#define PORT 8080

int main(int argc, char *const argv[])
{

    int client_sock,valread;
    struct sockaddr_in client_addr;
    int length=sizeof(client_addr);
    char buffer[1024]={0};
    char *hello="HELLO FROM CLIENT";

    client_addr.sin_family=AF_INET;
    client_addr.sin_port=htons(PORT);

    client_sock=socket(AF_INET,SOCK_STREAM,0);

    inet_pton(AF_INET,"127.0.0.1",&client_addr.sin_addr);

    connect(client_sock,(struct sockaddr*)&client_addr,length);

    send(client_sock,hello,strlen(hello),0);

    valread=read(client_sock,buffer,sizeof(buffer));

    return 0;
}