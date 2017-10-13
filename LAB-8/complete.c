//program to check if tree is complete or not

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *left,*right;
}*root;

struct node *newNode(int x)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=x;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}

int node_count(struct node *temp)
{
    if(temp==NULL)
        return 0;
    return 1+node_count(temp->left)+node_count(temp->right);
}

bool isComplete(struct node *temp,int indx,int nodes)
{
    if(temp==NULL)
        return true;
    if(indx>nodes)
        return false;
    return (isComplete(temp->left,2*indx,nodes)&&isComplete(temp->right,2*indx+1,nodes));
}

int main()
{
    root=newNode(1);

    root->left=newNode(2);
    root->right=newNode(3);

    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    //root->right->right=newNode(7);

    struct node *temp=root;
    int total_nodes=node_count(temp);

    temp=root;
    if(isComplete(temp,1,total_nodes))
        printf("Tree is a complete tree\n");
    else
        printf("Tree is not complete\n");

    return 0;
}
