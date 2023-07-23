#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/socket.h>
#define PORT 8080

int main(int argc, char *const argv[])
{

    int server_socket,new_server_socket,valread;
    struct sockaddr_in server_addr;
    int opt=1;
    int length=sizeof(server_addr);
    char buffer[1024]={0};
    char *hello="HELLO FROM SERVER";

    server_addr.sin_port=htons(PORT);
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=INADDR_ANY;

    server_socket=socket(AF_INET,SOCK_STREAM,0);

    setsockopt(server_socket,SOL_SOCKET,SO_REUSEADDR|SO_REUSEPORT,&opt,sizeof(opt));

    bind(server_socket,(struct sockaddr*)&server_addr,length);

    listen(server_socket,3);

    new_server_socket=accept(server_socket,(struct sockaddr*)&server_addr,(socklen_t*)&length);

    valread=read(new_server_socket,buffer,sizeof(buffer));
    printf("message received from client:%s\n",buffer);

    send(new_server_socket,hello,strlen(hello),0);
    printf("Message sent from server");



    return 0;
}