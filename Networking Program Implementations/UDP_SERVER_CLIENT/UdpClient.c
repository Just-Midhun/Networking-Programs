#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#define PORT 8080

int main(int argc, char *const argv[])
{

    int client_socket;
    struct sockaddr_in client_addr;
    int length=sizeof(client_addr);
    char buffer[1024]={0};
    char *hello="HELLO FROM CLIENT";

    client_addr.sin_family=AF_INET;
    client_addr.sin_port=htons(PORT);
    client_addr.sin_addr.s_addr=INADDR_ANY;

    client_socket=socket(AF_INET,SOCK_DGRAM,0);

    sendto(client_socket,hello,strlen(hello),0,(struct sockaddr*)&client_addr, length);


    return 0;
}
