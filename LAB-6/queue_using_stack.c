#include<stdio.h>
#include<string.h>

int stack1[12345],stack2[12345],top1=-1,top2=-1;

int topp2()
{
    return stack2[top2];
}

int topp1()
{
    return stack1[top1];
}
void push1(int x)
{
    top1++;
    stack1[top1]=x;
}

void push2(int x)
{
    top2++;
    stack2[top2]=x;
}

void pop1()
{
    top1--;
}

void pop2()
{
    top2--;
}

void enqueue(int x)
{
    push1(x);
}

void move1to2()
{
    while(top1!=-1)
    {
        push2(topp1());
        pop1();
    }
}
void move2to1()
{
    while(top2!=-1)
    {
        push1(topp2());
        pop2();
    }
}

void dequeue()
{
    move1to2();
    pop2();
    move2to1();

}


int front()
{
    move1to2();
    int temp=topp2();
    move2to1();
    return temp;
}


int main()
{
    printf("1]Enqueue\n2]Dequeue\n3]Front\n4]Exit\n");
    int c,x;
    while(1)
    {
        printf("Enter the choice :");
        scanf("%d",&c);
        switch(c)
        {
             case 1:
                   printf("Enter the element want to Insert:");
                   scanf(" %d",&x);
                   enqueue(x);
                   break;
             case 2:
                   dequeue();
                   break;
             case 3:
                   printf("Front element :%d\n",front());
                   break;
             case 4:
                   exit(1);
        }
    }
}
