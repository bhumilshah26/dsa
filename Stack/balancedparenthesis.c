#include<stdio.h>

char stack[10];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;

    return stack[top--];
}

int main() {
    char exp[10], x, y;
    int i = 0, counter = 0;
    printf("Enter the expression: ");
    scanf("%s", exp);

    while (exp[i] != '\0') {
        x = exp[i];
        if (x == '(' || x == '{' || x == '[')
            push(x);
        else if (x == ')' || x == '}' || x == ']') {
            y = pop();
            if (y != x - 1 && y != x - 2)
                counter++;
        }
        i++;
    }
    printf("%d counter %d top\n", counter, top);

    if (!counter && top == -1)
        printf("Expression is balanced\n");
    else
        printf("Expression is not balanced\n");

    return 0;
}
