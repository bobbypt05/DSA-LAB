//Dequeue using singly linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*temp,*rear,*front,*ptr;

void insertAtFront(int x)
{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    if(rear==NULL&&front==NULL)
    {
        rear=front=temp;
        temp->next=NULL;
        return ;
    }
    temp->next=front;
    front=temp;
    return ;
}

void insertAtBack(int x)
{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(rear==NULL&&front==NULL)
    {
        front=rear=temp;
        return ;
    }
    rear->next=temp;
    rear=temp;
    return ;
}

void DeleteFromFront()
{
    if(front==NULL)
    {
        printf("Dequeue is empty\n");
        return ;
    }
    if(front==rear&&front!=NULL)
    {

        ptr=front;
        front==NULL;
        rear==NULL;
        free(ptr);
        return ;
    }
    ptr=front;
    front=front->next;
    free(ptr);
    return ;
}

void DeleteFromback()
{
     if(rear==NULL)
     {
         printf("Dequeue is empty\n");
         return ;
     }
     if(front==rear&&rear!=NULL)
     {
         ptr=front;
         front=rear=NULL;
         free(ptr);
         return ;
     }
     ptr=front;
     while(ptr->next!=NULL)
     {
         temp=ptr;
         ptr=ptr->next;
     }
     temp->next=NULL;
     free(ptr);
     rear=temp;
     return ;
}

void display()
{
    if(front==NULL&&rear==NULL)
    {
        printf("Dequeue is empty\n");
        return ;
    }
    ptr=front;
    printf("Dequeue :");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    return ;
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
