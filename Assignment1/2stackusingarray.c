#include <stdio.h>
#include <stdlib.h>
#define size 20
int stack[size];
int top1 = -1;
int top2 = size;
void push1()
{
    int val;
    printf("Enter data\n");
    scanf("%d", &val);
    if (top1 < top2 - 1)
    {
        top1++;
        stack[top1] = val;
    }
    else
    {
        printf("Stack is full\n");
    }
}
void push2()
{
    int val;
    printf("Enter data\n");
    scanf("%d", &val);
    if (top1 < top2 - 1)
    {
        top2--;
        stack[top2] = val;
    }
    else
    {
        printf("Stack is full\n");
    }
}
void pop1()
{
    if (top1 == -1)
    {
        printf("Stack 1 is empty\n");
    }
    else
    {
        int val = stack[top1];
        top1--;
        printf("%d is popped from Stack 1\n", val);
    }
}
void pop2()
{
    if (top2 == size)
    {
        printf("Stack 2 is empty\n");
    }
    else
    {
        int val = stack[top2];
        top2++;
        printf("%d is popped from Stack 2\n", val);
    }
}
void display1()
{

    for (int i = top1; i >= 0; i--)
    {
        printf("%d \n", stack[i]);
    }
}
void display2()
{
    for (int i = top2; i < size; i++)
    {
        printf("%d \n", stack[i]);
    }
}
int main()
{
    int n;
    do
    {
        printf("Enter choice\n");
        printf("1. Push in stack 1\n");
        printf("2. Push in stack 2\n");
        printf("3. Pop from stack 1\n");
        printf("4. Pop from stack 2\n");
        printf("5. Display Stack 1\n");
        printf("6. Display stack 2\n");
        printf("7. Exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                push1();
                break;
            case 2:
                push2();
                break;
            case 3:
                pop1();
                break;
            case 4:
                pop2();
                break;
            case 5:
                display1();
                break;
            case 6:
                display2();
                break;
            case 7: printf("Exitting...\n");
                break;
            default: printf("Wrong choice\n");
        }
    } while (n != 7);
    return 0;
}