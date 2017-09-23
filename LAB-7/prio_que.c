// LAB7
// Name :- Bobby Patil
// Program :- Implement Priority queue using linked list

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void Enqueue(struct node **head,int x)
{
      struct node *ptr=(struct node*)malloc(sizeof(struct node));
      struct node *temp=*head,*p=*head;

      if(*head==NULL)
      {
           ptr->data=x;
           ptr->next=*head;   
           *head=ptr;
           return ; 
      }
      while(temp!=NULL&&temp->data > x)
      {  
             p=temp;
             temp=temp->next;                                                                                                                                                                                                                                                                                                                                          
      }
      if(temp==NULL)
      {
           ptr->data=x;
           p->next=ptr;
           ptr->next=temp;
           return ;
      }
      if(temp==*head)
      {
           ptr->data=x;
           ptr->next=*head;
           *head=ptr;
           return ;
      }
      ptr->data=x;
      ptr->next=temp;
      p->next=ptr;
      return ;


}

void print(struct node **head)
{
     struct node *temp=*head;
     while(temp!=NULL)
     {
         printf("%d ",temp->data);
         temp=temp->next;
     }
     return ;
}

int front(struct node **head)
{
   if(*head!=NULL)
     return (*head)->data;
   return 123456;
}

void Dequeue(struct node **head)
{
    if(*head==NULL)
    {
       printf("Empty\n");
       return ;
    }
    struct node *temp=*head;
    *head=temp->next;
    free(temp);
    return ;
}

int main()
{
     int choice,x;
    struct node *head=NULL;
      while(1)
     {
           printf("1]Enqueue\n2]Dequeue\n3]Front\n4]Exit\nEnter the operation want to perform:");
           scanf("%d",&choice);
           switch(choice)
           {
               case 1:
                      printf("Enter the element want to Insert:");
                      scanf("%d",&x);
                      Enqueue(&head,x);
                      break;
               case 2:
                      Dequeue(&head);
                      break;
               case 3:
                      front(&head)!=123456?printf("Front element : %d\n",front(&head)):printf("Queue is empty\n");
                      break;
               case 4:
                      exit(1);
            }
     }
     return 0;
}

