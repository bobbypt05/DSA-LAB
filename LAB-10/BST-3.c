//bobbypt05
//given nodes find the height

#include<stdio.h>
#include<math.h>

int main()
{
    int N,H;
    printf("Enter the number of nodes :");
    scanf("%d",&N);
    printf("Maximum Height = %d\n",(int)(ceil(log(N+1))));
}
