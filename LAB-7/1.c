// LAB-7
// Name :- Bobby Patil
// Program :- Checking string is palindrome or not using stack

#include<stdio.h>

char stack[1234];
int top=-1;

void pop()
{
    if(top!=-1)
    {
         top--;
    }
    return ;
}

char topp()
{
       return stack[top];
}

int IsEmpty()
{
    if(top==-1)
        return 1;
    return 0;
}

void push(char x)
{
     top++;
     stack[top]=x;
}

int main()
{
    char str[1234];
    printf("Enter the string want to check:");
    scanf("%s",str);
    int i;
    for(i=0;i<strlen(str);i++)
    {
         push(str[i]);
    }
    i=0;
    while(IsEmpty()==0)
    {
         if(str[i]!=topp())
             break;
         pop();
         i++;
    }
    if(IsEmpty())
    {
        printf("Entered string Is Panlindrome\n");
    }
    else
    {
        printf("Entered string Is not Panlindrome\n");
    }
    return 0;
}    
