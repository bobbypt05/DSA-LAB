//program to build expression tree from Infix expression

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node
{
    char data;
    struct node *left,*right;
};

char s[12344],postfix[100];
int top=-1,toppp=-1;
struct node *stack[100];

void push(char a)
{
    top++;
    s[top]=a;
}

int Empty()
{
    if(top==-1)
        return 1;
    return 0;
}

void pop()
{
    top--;
}

char topp()
{
    return s[top];
}

int pre(char x)
{
    switch(x)
    {
        case '+':
        case '-':
                return 1;
        case '*':
        case '/':
                return 2;
        case '^':
                 return 3;
    }
    return -1;
}

void convert_postfix(char str[])
{
    int i=0,k=0;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]>='0'&&str[i]<='9')
            postfix[k++]=str[i];
        else if(str[i]==')')
        {
            while(topp()!='('&&!Empty())
            {
                postfix[k++]=topp();
                pop();
            }
            pop();
        }
        else if(str[i]=='(')
            push(str[i]);
        else
        {
            if(pre(str[i])>pre(topp()))
            {
                push(str[i]);
            }
            else
            {
                while(!Empty()&&pre(str[i])<=pre(topp()))
                {
                    postfix[k++]=topp();
                    pop();
                }
                push(str[i]);
            }
        }

    }
    while(!Empty())
    {
        postfix[k++]=topp();
        pop();
    }
    postfix[k]='\0';
    printf("PostFix Expression : %s",postfix);
}

struct node *newNode(char x)
{
        struct node *ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=x;
        ptr->left=NULL;
        ptr->right=NULL;
        return ptr;
}

struct node *popp()
{
        return stack[toppp--];
}

void pushp(struct node *temp)
{
    stack[++toppp]=temp;
}

void Inorder(struct node *temp)
{
    if(temp!=NULL)
    {
        Inorder(temp->left);
        printf(" %c",temp->data);
        Inorder(temp->right);
    }
}

void Preorder(struct node *temp)
{
    if(temp!=NULL)
    {
        printf(" %c",temp->data);
        Preorder(temp->left);
        Preorder(temp->right);
    }
}

void Postorder(struct node *temp)
{
    if(temp!=NULL)
    {
        Postorder(temp->left);
        Postorder(temp->right);
        printf(" %c",temp->data);
    }
}

void construct_tree()
{
    int i=0;
    struct node *temp=NULL;
    for(i=0;postfix[i];i++)
    {
        if(postfix[i]=='*'||postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='/')
        {
            temp=newNode(postfix[i]);
            temp->right=popp();
            temp->left=popp();
            pushp(temp);
        }
        else
        {
            temp=newNode(postfix[i]);
            pushp(temp);
        }
    }
    printf("\nInoder :");
    Inorder(temp);
    printf("\nPreorder:");
    Preorder(temp);
    printf("\nPostorder:");
    Postorder(temp);
}


int main()
{
    char str[123456],i,k=0;
    printf("Enter the Infix operation :");
    scanf("%s",str);
    convert_postfix(str);
    construct_tree();
    return 0;
}
