//To check whether tree is full or not

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

bool isFull(struct node *temp)
{
    if(temp==NULL)
        return true;
    if(temp->left==NULL&&temp->right==NULL)
        return true;
    if(temp->left&&temp->right)
        return (isFull(temp->left)&&isFull(temp->right));
    return false;
}

int main()
{
    root=newNode(1);

    root->left=newNode(2);
    root->right=newNode(3);

    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);

    struct node *temp=root;
    if(isFull(temp))
        printf("Tree is a full tree\n");
    else
        printf("Tree is not full\n");

    return 0;
}
