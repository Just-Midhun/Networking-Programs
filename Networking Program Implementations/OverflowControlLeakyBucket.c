#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *const argv[])
{
    int number, outgoing,incoming,buck_size,store=0;

    printf("Enter the number of packets and outgoing limit and bucket size:");
    scanf("%d%d%d", &number,&outgoing,&buck_size);

    int n=number;

    while(number!=0)
    {
        printf("\nEnter the size of packet %d",n-number+1);
        scanf("%d", &incoming);

        if(incoming>buck_size-store)
        {
            printf("\n%d packets dropped",incoming-(buck_size-store));
            store=buck_size;
            printf("\npackets inside before passing:%d",store);
            
        }

        else
        {
            store=store+incoming;
            printf("\npackets inside before passing:%d",store);      
        }

        store=store-outgoing;
        
        if(store<0)
        store=0;

        printf("\npackets inside after passing:%d",store);
        number--;
    }

    return 0;
}