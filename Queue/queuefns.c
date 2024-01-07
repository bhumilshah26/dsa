#include<stdio.h>
#define Size 10
int queue[Size];
int front = - 1, rear = -1;

void enqueue(){
    int val;
    printf("Enter the value:");
    scanf("%d", &val);
    
    if(rear == Size - 1)
        printf("Queue Overflow");
    else if(rear == -1)
        front++;
    queue[++rear] = val;
 
}

int dequeue(){
    int x = -1;
    if(front == -1)
        printf("Queue Empty");
    else 
        x = queue[front++];
    return x;
}

void display(){
    for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}
int main(){
    int option, del;
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
            case 2: del = dequeue();
            printf("%d deleted\n", del);
            break;
            case 3: display();
            break;
            case 4: return 0;
            default:
            printf("Invalid");

        } 
    } while(option != 4);
    return 0;
}