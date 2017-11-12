/*
        Bellman - Ford Algorithm for finding shortest path
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
    int u,v,w;
}B[1000];

int dist[1000];

void init(int N)
{
    int i;
    for( i=0 ; i <= N ; i++)
        dist[i]=100000;
}

int main()
{
        int i,j,N,E;
        printf("Enter the number of nodes and edges :");
        scanf("%d %d",&N,&E);
        for(i=0;i<E;i++)
        {
                printf("Enter the from to and weight :");
                scanf("%d %d %d",&B[i].u,&B[i].v,&B[i].w);
        }

        init(N);

        dist[0] = 0;

        for(i=0;i<N-1;i++)
        {
            for(j=0;j<E;j++)
            {
                if( dist[B[j].u]+B[j].w < dist[B[j].v] )
                    dist[B[j].v] = dist[B[j].u]+B[j].w;
            }
        }

        for( i=0 ; i <= N ;i++ )
        {
            printf(" Shortest path  of %d -> %d \n" , i , dist[i] );
        }

}
