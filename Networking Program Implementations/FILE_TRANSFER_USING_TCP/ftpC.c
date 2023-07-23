#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#define PORT 8080

int main(int argc, char *const argv[]){
    FILE *fp;

    int clientsock;
    struct sockaddr_in clientaddr;
    int length=sizeof(clientaddr);
    char name[100],fname[100];


    clientaddr.sin_family=AF_INET;
    clientaddr.sin_port=htons(PORT);

    clientsock=socket(AF_INET,SOCK_STREAM,0);
    inet_pton(AF_INET,"127.0.0.1",&clientaddr.sin_addr);
    connect(clientsock,(struct sockaddr*)&clientaddr,length);

    

    printf("Enter already existing file name: \n");
    scanf("%s",&name);

    send(clientsock,name,sizeof(name),0);

    printf("Enter new file name: \n");
    scanf("%s",&fname);

    fp=fopen(fname,"w");

    int s;
    char rcvg[500];

    while(1)
    {
        s=recv(clientsock,rcvg,500,0);
        rcvg[s]='\0';

        if(strcmp(rcvg,"error")==0)
        {
            printf("File not available\n");
            break;
        }

        if(strcmp(rcvg,"completed")==0)
        {
            printf("FILE transfer complete\n");
            break;
        }

        else
        {
            fputs(rcvg,stdout);
            fprintf(fp,"%s",rcvg);
            break;
        }
        return 0;
    }

}