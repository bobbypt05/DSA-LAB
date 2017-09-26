#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **head,int x)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=x;
    ptr->next=*head;
    *head=ptr;
    return ;
}

int pop(struct node **head)
{
    if(*head==NULL)
    {
        printf("List is empty\n");
        return ;
    }
    struct node *ptr=*head;
    *head=(*head)->next;
    int temp=ptr->data;
    free(ptr);
    return temp;
}

void display(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return ;
    }
    printf("List :");
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
    return ;
}

void InsertAtBottom(struct node **head,int x)
{
    if((*head)==NULL)
    {
        push(head,x);
    }
    else
    {
        int temp=pop(head);
        InsertAtBottom(head,x);

        push(head,temp);
    }
}

void sortedInsert(struct node **head,int x)
{
    if(*head==NULL||x<(*head)->data)
        push(head,x);
    else
    {
        int temp=pop(head);
        sortedInsert(head,x);
        push(head,temp);
    }
}

void sort(struct node **head)
{
    if(*head!=NULL)
    {
        int temp=pop(head);
        sort(head);
        sortedInsert(head,temp);
    }
}

void reverse(struct node **head)
{
        if((*head)!=NULL)
        {
            int temp=pop(head);
            reverse(head);

            InsertAtBottom(head,temp);
        }
}

int main()
{
    printf("1]push\n2]pop\n3]display\n4]sort\n5]Exit\n");
    int x,c;
    struct node *head=NULL;
    while(1)
    {
        printf("Enter the choice :");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                   printf("Enter the element :");
                   scanf("%d",&x);
                   push(&head,x);
                   break;
            case 2:
                   pop(&head);
                   break;
            case 3:
                   display(head);
                   break;
            case 4:
                   sort(&head);
                   break;
            case 5:
                   exit(1);
        }
    }
}
