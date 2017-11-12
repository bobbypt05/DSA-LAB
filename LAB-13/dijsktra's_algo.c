/*
    Dijsktra's Algorithm for finding shortest path
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int graph[1000][1000],dist[1000];
bool visited[1000];

void initialise()
{
    int i;
    for(i=0;i<1000;i++)
    {
        dist[i] = 100000;
    }
}

int getMIN(int N)
{
    int i,MAX = 100000 , indx = 0 ;
    for( i = 0 ; i < N ; i++ )
    {
        if( visited[i] == false && dist[i] <=  MAX  )
        {
            MAX = dist[i];
            indx = i;
        }
    }
    return indx;
}

int main()
{
    int N,E,u,v,w,i,j;
    printf("Enter the nodes and number of edges of graph :");
    scanf("%d %d",&N,&E);

    for( i=0 ; i < E ; i++ )
    {
        printf("Enter the from to and weight of vertex :");
        scanf("%d %d %d",&u,&v,&w);
        graph[u][v]=w;
        graph[v][u]=w;
    }

    initialise();

    dist[0] = 0;

    for( i = 0 ; i < N-1 ; i++ )
    {
        int MINI = getMIN( N );

        visited[MINI] = true ;

        for( j = 0 ; j < N ;j++)
        {
              if( visited[j] == false && graph[MINI][j] && dist[MINI] != 100000 && dist[MINI] + graph[MINI][j] < dist[j] )
                        dist[j] = dist[MINI] + graph[MINI][j];
        }
    }

    for(i = 0 ;i < N ; i++ )
        printf(" %d %d \n",i ,dist[i]);
}
