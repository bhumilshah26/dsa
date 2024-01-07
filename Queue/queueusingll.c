#include <stdio.h>
#include <stdlib.h>
#define sn struct node
sn{
    int data;
    sn *next;
} *front = NULL, *rear = NULL;
void enqueue() {
    sn *nn;
    int val;
    nn = (sn *)malloc(sizeof(sn));
        printf("Enter the node to be inserted:\n");
        scanf("%d", &val);
        nn -> data = val;
        nn -> next = NULL;
    if (rear == NULL)
        front = nn;
    else
        rear -> next = nn;
    rear = nn;
}

int dequeue(){
    sn *temp;
    int val = -1;
    temp = front;
    if (front == NULL)
        printf("Queue is empty");
    else {
        val = front -> data;
        if (front == rear) 
            front = rear = NULL;
        else 
            front = front -> next;
    }
    free(temp); 
    return val; 
}

void display() {
    sn *temp;
    temp = front;
    if (front == NULL)
        printf("Queue is empty");
    else {
        printf("QUEUE:\n");
        while (temp != NULL) {
            printf("%d ", temp -> data);
            temp = temp -> next;
        }
    }
    printf("\n");
}

int main()
{
    int choice, del;
    do {
        printf("Enter \n1.Enqueue \n2.Dequeue \n3.Display\n4.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            enqueue();
            break;
        case 2:
            del = dequeue();
            printf("%d deleted\n", del);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid input");
        }
    } while (choice != 4);
    return 0;
}
