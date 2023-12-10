#include<stdio.h>
#define Size 10
int queue[10];
int front = -1, rear = -1;


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

void reverse(int k){
    int temp = front, i, j;
    while(--k)
        temp++;
    for(j = front; j <= temp / 2; j++){
        i = queue[j];
        queue[j] = queue[temp - j];
        queue[temp - j] = i;
    }  
}

int main(){
    int option, k;
    do{
        printf("Menu:\n");
        printf("1.Enqueue:\n");
        printf("2.Dequeue:\n");
        printf("3.Display:\n");
        printf("4.Reverse at k:\n");
        printf("5.Exit:\n");
        printf("Enter choice: ");
        scanf("%d", &option);
        switch(option){
            case 1:enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: display();
            break;
            case 4: {
                printf("Enter k:");
                scanf("%d", &k);
                reverse(k);
                break;
            }
            case 5:
            exit(0);
            default:
            printf("Invalid");
        }
    } while(option != 5);
    return 0;
}