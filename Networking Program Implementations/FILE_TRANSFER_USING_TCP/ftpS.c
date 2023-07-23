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
    FILE *fp;
    
    int serversock,newserversock,opt=1,s;
    struct sockaddr_in serveraddr;
    char rvcg[500];
    int length=sizeof(serveraddr);

    serveraddr.sin_port=htons(PORT);
    serveraddr.sin_addr.s_addr=INADDR_ANY;
    serveraddr.sin_family=AF_INET;

    serversock=socket(AF_INET,SOCK_STREAM,0);
    setsockopt(serversock,SOL_SOCKET,SO_REUSEADDR|SO_REUSEPORT,&opt,sizeof(opt));
    bind(serversock,(struct sockaddr*)&serveraddr,length);
    listen(serversock,5);
    newserversock=accept(serversock,(struct sockaddr*)&serveraddr,(socklen_t*)&length);

    s=recv(newserversock,rvcg,sizeof(rvcg),0);
    rvcg[s]='\0';

    fp=fopen(rvcg,"r");

    if(fp==NULL){
        send(newserversock,"error",5,0);
        close(newserversock);
    }

    else
    {
        while(fgets(rvcg,sizeof(rvcg),fp))
        {
            send(newserversock,rvcg,sizeof(rvcg),0);
            sleep(1);
        }

        if(!fgets(rvcg,sizeof(rvcg),fp))
        send(newserversock,"completed",999999999,0);
    
        return 0;
    }
    

}