#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

void main()
{   
    int frames,frame[100];
    printf("Enter the number of frames to be sent:");
    scanf("%d", &frames);

    printf("\n\nEnter the frames:");
    for(int i=0;i<frames;i++)
    scanf("%d", &frame[i]);

    int ack,sent=0,windowSize;

    printf("\nEnter the window size:");
    scanf("%d", &windowSize);

    while(sent!=frames)
    {
        for(int i=0;i<windowSize;i++)
        {   
            if(sent<frames)
            {   
                printf("Frame %d sent\n",frame[sent]);
                sent++;
            }

        }

        printf("\nEnter the last acknowledgement received:");
        scanf("%d", &ack);

        if(ack<sent)
        sent=sent-ack;
    }
}