//Dequeue using stack

#include<stdio.h>

int stack1[123],stack2[123],top1=-1,top2=-1;

void insertAtFront(int x)
{
    top1++;
    stack1[top1]=x;
    return ;
}

void insertAtBack(int x)
{
    while(top1!=-1)
    {
        top2++;
        stack2[top2]=stack1[top1];
        top1--;
    }
    top2++;
    stack2[top2]=x;
    while(top2!=-1)
    {
        top1++;
        stack1[top1]=stack2[top2];
        top2--;
    }
    return ;
}

void DeleteFromFront()
{
    if(top1==-1)
    {
        printf("Queue is empty\n");
        return ;
    }
    top1--;
    return ;
}

void DeleteFromback()
{
    if(top1==-1)
    {
        printf("Queue is empty\n");
        return ;
    }
    while(top1!=-1)
    {
        top2++;
        stack2[top2]=stack1[top1];
        top1--;
    }
    top2--;
    while(top2!=-1)
    {
        top1++;
        stack1[top1]=stack2[top2];
        top2--;
    }

    return ;
}

void display()
{
    if(top1==-1)
    {
        printf("Queue is empty\n");
        return ;
    }
    int i=top1;
    while(i!=-1)
    {
        printf("%d ",stack1[i]);
        i--;
    }
    printf("\n");
}

int main()
{
    printf("1]InserAtFront\n2]InsertAtBack\n3]DeleteFromFront\n4]DeleteFromBack\n5]display\n6]exit\n");
    int x,c;
    while(1)
    {
        printf("Enter the choice :");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                   printf("Enter data:");
                   scanf("%d",&x);
                   insertAtFront(x);
                   break;
            case 2:
                   printf("Enter data:");
                   scanf("%d",&x);
                   insertAtBack(x);
                   break;
            case 3:
                  DeleteFromFront();
                  break;
            case 4:
                  DeleteFromback();
                  break;
            case 5:
                   display();
                   break;
            case 6:
                   exit(1);
        }
    }
}
