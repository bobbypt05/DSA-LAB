//Given Preorder and Inorder Traversal construct tree

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct node
{
    char data;
    struct node *left,*right;
};

struct node *newNode(char x)
{
     struct node *ptr=(struct node*)malloc(sizeof(struct node));
     ptr->data=x;
     ptr->left=NULL;
     ptr->right=NULL;
     return ptr;
}

int Search(char in[],int start,int end,char key)
{
    int i;
    for(i=start;i<=end;i++)
    {
        if(in[i]==key)
            return i;
    }
}

struct node *buildTree(char pre[],char in[],int first,int last)
{
       static int ptr=0;

       if(first>last)
          return NULL;

       struct node *pCrawl=newNode(pre[ptr++]);

       if(first==last)
          return pCrawl;

       int indx=Search(in,first,last,pCrawl->data);

       pCrawl->left=buildTree(pre,in,first,indx-1);
       pCrawl->right=buildTree(pre,in,indx+1,last);

}

void Inorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        Inorder(ptr->left);
        printf(" %c",ptr->data);
        Inorder(ptr->right);
    }
}

int main()
{
      char pre[1000],in[1000];
      printf("Enter the inorder traversal :");
      scanf("%s",in);
      printf("Enter the preorder traversal :");
      scanf("%s",pre);

      struct node *root=buildTree(pre,in,0,strlen(in)-1);

      printf("InOrder traversal of the constructed tree :");
      Inorder(root);

      return 0;
}

