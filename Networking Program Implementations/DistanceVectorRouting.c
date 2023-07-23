#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

struct node{
    unsigned dist[20];
    unsigned from[20];
}rt[10];
//Creating a structure to save the chnages for node values.

int main(int argc, char *const argv[])
{   
    int nodes,costmat[100][100],count;
    //Costmatrix is for temporary saved values of nodes.

    printf("Enter the number of nodes to create the dvr of:");
    scanf("%d", &nodes);

    printf("\nEnter the cost matrix:");
    for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<nodes;j++)
        {
            scanf("%d", &costmat[i][j]);
            rt[i].dist[j] = costmat[i][j];
            rt[i].from[j] = j;
        }
    }
    

    do
    {
        count=0;

    for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<nodes;j++)
        {
            for(int k=0;k<nodes;k++)
            {
                if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
                {
                    rt[i].dist[j] = rt[i].dist[k]+rt[k].dist[j];
                    rt[i].from[j] = k;
                    count++;
                }
                //Used to continuously check for possible shortest routing by using BELLMAN-FORD EQUATION
            }
        }
    }

    }
    while(count!=0);

    for(int i=0; i<nodes; i++)
    {
        printf("\n\n For Router %d\n",i+1);

        for(int j=0; j<nodes; j++)
        {
            printf("Shortest distance to  %d from %d = %d\n",j+1,rt[i].from[j],rt[i].dist[j]);
        }

    }

    return 0;

}
