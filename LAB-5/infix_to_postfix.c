#include<stdio.h>
#include<string.h>


char s[12344];
int top=-1;

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

int main()
{
    char str[123456],postfix[123456],i,k=0;
    printf("Enter the Infix operation :");
    scanf("%s",str);
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]>='a'&&str[i]<='z')
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
