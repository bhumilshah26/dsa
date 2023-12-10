#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

float stack[50];
char prefix[50];
int top = -1;

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

void evaluate(){
    char x, y;
    float op2, op1, result;
    int i = 0;
    while(prefix[i] != '\0'){
        i++;
    }
    while(i){
        x = prefix[i];
        if(isalpha(x) || isdigit(x)){
            y = (float)x - '0';
            push(y);
        }

        else if(x == '+' || x == '-' || x == '*' || x == '/' || x == '%'){
            op2 = pop();
            op1 = pop();
            if(x == '+')
            result = op1 + op2;

            else if(x == '-')
            result = op2 - op1;

            else if(x == '*')
            result = op2 * op1;

            else if(x == '/')
            result = op2 / op1;

            else if(x == '%')
            result = (int)op2 % (int)op1;

            push(result);
            
        }
        i--;
    }
     printf("\nResult: %.2f",stack[top]);
}

int main(){
    printf("Enter the Prefix expression: \n");
    scanf("%s",prefix);
    evaluate();
    return 0;
}