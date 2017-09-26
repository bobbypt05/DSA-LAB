#include<stdio.h>
#include<string.h>

char stack[1234][1234];
int topp=-1;

void push(char temp[])
{
      topp++;
      strcpy(stack[topp],temp);
}

char *pop()
{
    return stack[topp--];
}



int main()
{
    char pre[12345],temp[2],op1[1234],op2[1234],str[12345];int i;
    printf("Enter the prefix expression :");
    scanf("%s",pre);
    for(i=strlen(pre)-1;i>=0;i--)
    {
        temp[0]=pre[i];
        temp[1]='\0';
        if(!(pre[i]>='a'&&pre[i]<='z'))
        {
            strcpy(op1,pop());
            strcpy(op2,pop());
            //printf("%s %s %s\n",op1,op2,temp);
            strcpy(str,op1);
            strcat(str,op2);
            strcat(str,temp);
            push(str);
        }
        else
        {
            push(temp);
        }
    }
    printf("%s",stack[0]);
}
