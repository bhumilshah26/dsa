#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char infix[100], prefix[100], stack[100];
int top = -1;           //stack

void push(char a) {
    top++;
    stack[top] = a;
}

char pop() {
    char a = stack[top--];
    return a;
}

int priority(char a)
{
    if (a == '%' || a == '^')
        return 3;
    else if (a == '*' || a == '/')
        return 2;
    else if (a == '+' || a == '-')
        return 1;
    else
        return 0;

}

void reverse(char a[]){
   char temp;
   int i = 0, length = 0;
   for(i = 0; a[i] != '\0'; i++)
    length++;

   for(i = 0; i < length / 2; i++){
    temp = a[i];
    a[i] = a[length - i - 1];
    a[length - i - 1] = temp;
   }
    for(i = 0; i < length; i++){
        if(a[i] == '(')
        a[i] = ')';

        else if(a[i] == ')')
        a[i] = '(';
    }
}

void infixtoprefix()
{
    int i = 0, j = 0;
    char x, y;
    while (infix[i] != '\0')
    {
        x = infix[i];
        if (isalpha(x) || isdigit(x))
        {

            prefix[j++] = x;
        }
        else if (x == '(')
        {
            push(x);
        }
        else if (x == '+' || x == '-' || x == '/' || x == '*' || x == '^' || x == '%')
        {
            while (top != -1 && (priority(x) < priority(stack[top])))
            {
                y = pop();
                prefix[j++] = y;
            }
            push(x);
        }
        else if (x == ')')
        {
            y = pop();
            while (y != '(')
            {
                prefix[j++] = y;
                y = pop();
            }
        }
        else {
            printf("Expression not correct!");
            break;
        }
        i++;
    }
    while (top != -1)
    {
        y = pop();
        prefix[j] = y;
        j++;
    }
}
int main()
{
    printf("Enter the infix expression:\n");
    scanf("%s", infix);
    printf("Infix Statement:\n%s\n", infix);
    reverse(infix);
    infixtoprefix();
    reverse(prefix);
    printf("Prefix Statement:\n%s\n", prefix);

    return 0;
}
