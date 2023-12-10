#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *front, *rear;
void enqueue()
{
    struct node *nn;
    int val;
    nn = (struct node *)malloc(sizeof(struct node));
        printf("Enter the node to be inserted:\n");
        scanf("%d", &val);
        nn -> data = val;
        nn -> next = NULL;
    if (rear == NULL)
    {
        rear = nn;
        front = nn;
    }
    else
    {

        rear -> next = nn;
        rear = nn;
    }
}
void dequeue()
{
    struct node *temp;
    int val;
    if (front == NULL)
    {
        printf("Queue is empty");
    }
    else if (front == rear)
    {
        val = front -> data;
        printf("Deleted value: %d", val);
        temp = front;
        front = NULL;
        rear = NULL;
        free(temp);
    }
    else
    {
        val = front -> data;
        printf("Deleted value: %d", val);
        temp = front;
        front = front -> next;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    temp = front;
    if (front == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("QUEUE:\n");
        while (temp != NULL)
        {
            printf("%d ", temp -> data);
            temp = temp -> next;
        }
    }
    printf("\n");

}
int main()
{
    int choice;
    printf("Enter \n1.Enqueue \n2.Dequeue \n3.Display:\n4.Exit");
    scanf("%d", &choice);
    do
    {
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
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
        printf("Enter \n1.insert \n2.delete \n3.display \n0.exit: \n");
        scanf("%d", &choice);
    } while (choice != 4);
    return 0;
}
