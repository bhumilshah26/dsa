#include<stdio.h>

#define size 5
int stack[size];
int top = -1;

void push(int x){
    if(top == size - 1)
    printf("Stack Overflow!");

    else
    stack[++top] = x;
}

int pop(){
    int x = -1;
    if(top == -1)
    printf("Stack Empty!");

    else
    x = stack[top--];

    return x;
}

// see the topmost element
void peek(){
    if(top == -1)
    printf("Stack Empty!");

    else
    printf("%d",stack[top]);
}

// LIFO principle
void display(){
    int i;
    if(top == -1)
    printf("Stack Empty");

    else{
        for(i = top; i >= 0; i--){
            printf("%d ",stack[i]);
        }
    }
    printf("\n");
}

int main() {
    int i, iteration = 0, val;

    do{
        printf("*  Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("Enter the option no: ");
        scanf("%d",&i);

        switch(i){
            case 1:
            printf("Enter the value to be pushed: ");
            scanf("%d",&val);
            push(val);
            break;

            case 2:
            val = pop();
            printf("Deleted value = %d\n", val);
            break;

            case 3:
            peek();
            break;

            case 4:
            display();
            break;

            default:
            printf("Invalid Input!");

            iteration++;
        }
    } while(iteration <= 5);

    return 0;
}
