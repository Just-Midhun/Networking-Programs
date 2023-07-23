#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#define PORT 8080

int main(int argc, char *const argv[])
{
    int server_sock;
    struct sockaddr_in server_addr;
    int length =sizeof(server_addr);
    char buffer[1024]={0};
    char *hello="HELLO FROM SERVER";

    server_addr.sin_family = AF_INET;
    server_addr.sin_port=htons(PORT);
    server_addr.sin_addr.s_addr=INADDR_ANY;

    server_sock=socket(AF_INET,SOCK_DGRAM,0);

    bind(server_sock,(struct sockaddr*)&server_addr, length);

    recvfrom(server_sock,buffer,sizeof(buffer),0,(struct sockaddr*)&server_addr,(socklen_t*)&length);

    printf("GOT THE DATAGRAM:%s",buffer);

    return 0;
}