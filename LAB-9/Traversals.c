//Inorder , Preorder and Postorder traversal using array

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int Tree[123456];

void Insert(int x,int root)
{
    if(Tree[root]==0)
    {
        Tree[root]=x;
        return ;
    }
    int c;
    printf("To Insert left enter 1 for right press 2 : ");
    scanf("%d",&c);
    if(c==1)
        Insert(x,2*root);
    else
        Insert(x,2*root+1);
}



void Preorder(int root)
{
    if(Tree[root]!=0)
    {
        printf(" %d",Tree[root]);
        Preorder(2*root);
        Preorder(2*root+1);
    }
}

void Postorder(int root)
{
    if(Tree[root]!=0)
    {
        Postorder(2*root);
        Postorder(2*root+1);
        printf(" %d",Tree[root]);
    }
}

void Inorder(int root)
{
    if(Tree[root]!=0)
    {
        Inorder(2*root);
        printf(" %d",Tree[root]);
        Inorder(2*root+1);
    }
}

int main()
{
    int x,c;
    printf("1]Insert\n2]Traversal\n3]Exit\n");
    while(1)
    {
           printf("Enter the choice :");
           scanf("%d",&c);
           switch(c)
           {
               case 1:
                       printf("Enter the element want to insert :");
                       scanf("%d",&x);
                       Insert(x,1);
                       break;
               case 2:
                      printf("\nInorder traversal :");
                      Inorder(1);
                      printf("\nPreorder traversal :");
                      Preorder(1);
                      printf("\nPostorder traversal :");
                      Postorder(1);
                      printf("\n");
                      break;
               case 3:
                      exit(1);
           }
    }
}


