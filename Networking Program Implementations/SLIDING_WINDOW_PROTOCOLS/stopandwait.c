#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

void main()
{
    int frames,frame[100],randTime,windowSize=5;
    printf("Enter the number of frames to be sent");
    scanf("%d", &frames);

    printf("\nEnter the frames:");
    for(int i=frames;i>0;i--)
    scanf("%d", &frame[i]);

    while(frames!=0)
    {   
        printf("Frame %d sent",frame[frames]);
        randTime=rand()%10;
        if(randTime>=windowSize)
        {
            sleep(randTime);
            printf("acknowledgement not received\n");
        }
        else
        {
            sleep(randTime);
            printf("acknowledgement received for frame %d\n", frame[frames]);
            frames--;
        }
    }
}