/*
    Prim's algorithm for minimum spanning tree
*/

#include<stdio.h>
#include<stdbool.h>

int graph[1000][1000],dist[1000],parent[1000];
bool visited[1000];

void initialise(int N)
{
    int i=0;
    for(i=0;i<N;i++)
        dist[i]=100000;
    return ;
}

int getMIN(int N)
{
    int i = 0,MINI = 100000,indx;
    for(i = 0 ; i < N ; i++)
    {
        if( visited[i] == false && MINI > dist[i] )
        {
             MINI = dist[i];
             indx = i;
        }
    }
    return indx;
}

int main()
{
    int i,j,u,v,N,E,w;
    printf("Enter the number of nodes and edges :");
    scanf("%d %d",&N,&E);

    for(i=0;i<E;i++)
    {
        printf("Enter the from to and weight :");
        scanf("%d %d %d",&u,&v,&w);
        graph[u][v]=w;
        graph[v][u]=w;
    }

    initialise(N);

    dist[0]=0;

    for( i = 0 ;i < N-1 ; i++ )
    {
        int MINI = getMIN( N );
        visited[MINI] = true;

        for( j = 0 ; j < N ; j++ )
        {
            if( visited[j]  == false && graph[MINI][j] && graph[MINI][j] < dist[j] )
            {
                dist[j] = graph[MINI][j];
                parent[j] = MINI;
            }
        }

    }

    printf(":::::: MINIMUM SPANNING TREE ::::::\n\n");

    for(i=1 ; i < N ;i++ )
        printf("%d - > %d \n",parent[i] , i );
}
