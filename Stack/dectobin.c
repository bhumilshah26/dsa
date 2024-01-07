#include<stdio.h>
#include<stdlib.h>

int stack[10];
int top = -1;
int num;

void push(int val){

    if(top == 10 - 1)
    printf("Stack overflow!");

    else
    stack[++top] = val;

}

int pop(){

    int x = -1;
    if(top == -1)
    printf("Stack Empty!");

    else
    x = stack[top--];

    return x; 

}

void display(){

    int i = top;
    while(i != -1){
        printf("%d",stack[i--]);
    }

}
void dec_to_bin(){

    int i, remainder;
    while(num){
        remainder = num % 2;
        num /= 2;
        push(remainder);
    }

}
int main(){

    printf("Enter the decimal number: ");
    scanf("%d", &num);
    dec_to_bin();
    printf("Binary of the number is: ");
    display();

    return 0;

}