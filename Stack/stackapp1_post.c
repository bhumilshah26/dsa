    #include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char infix[100], postfix[100], stack[100];
int top = -1;           //stack

void push(char a)
{
    top++;
    stack[top] = a;
}

char pop()
{
    char a = stack[top--];
    return a;
}

int priority(char a)
{
    if (a == '%' || a == '^')
        return 3;
     if (a == '*' || a == '/')
        return 2;
     if (a == '+' || a == '-')
        return 1;
    else
        return 0;

}

void infixtopost()
{
    int i = 0, j = 0;
    char x, y;
    while (infix[i] != '\0')
    {
        x = infix[i]; 
        if (isalpha(x) || isdigit(x))
        {
            postfix[j++] = x;
        }
        else if (x == '(')
        {
            push(x);
        }
        else if (x == '+' || x == '-' || x == '/' || x == '*' || x == '^' || x == '%')
        {
            while (top != -1 && (priority(x) <= priority(stack[top])))
            {
                y = pop();
                postfix[j++] = y;
            }
            push(x);
        }
        else if (x == ')')
        {
            y = pop();
            while (y != '(')
            {
                postfix[j++] = y;
                y = pop(); 
            }
        }
        else
        {
            printf("Expression not correct!");
        }
        i++;
    }
    while (top != -1)
    {
        y = pop();
        postfix[j] = y;
        j++;
    }
}
int main()
{
    printf("Enter the infix expression:\n");
    scanf("%s", &infix);
    printf("Infix Statement:\n%s\n", infix);
    infixtopost();
    printf("Postfix Statement:\n%s\n", postfix);

    return 0;
}
