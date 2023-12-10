#include<stdio.h>
#define Size 10
int queue[Size];
int front = - 1, rear = -1;

void enqueue(){
    int val;
    printf("Enter the value:");
    scanf("%d", &val);
    if(front == -1){
        front++;
        rear++;
        queue[front] = val;
    }
    else if(rear == Size - 1)
        printf("Queue Overflow");
    else {
        rear++;
        queue[rear] = val;
    }   
}

void dequeue(){
    int x;
    if(front == -1)
        printf("Queue Empty");
    else {
        x = queue[front];
        front++;
        printf("%d is deleted", x);
    }
}

void display(){
    for(int i = front; i <= rear; i++)
        printf("%d ",queue[i]);
    printf("\n");
}
int main(){
    int option;
    do{
        printf("Menu:\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch(option){
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: display();
            break;
            case 4: exit(0);
            default:
            printf("Invalid");

        } 
    } while(option != 4);
    return 0;
}