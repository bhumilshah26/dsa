#include<stdio.h>
#include<stdlib.h>
#define sn struct Node

struct Node{
    int data, priority;
    struct Node *next;
}*start = NULL;

void insert(){
    sn *nn, *temp;
        nn = (sn *)malloc(sizeof(sn));
        nn -> next = NULL;
        printf("Enter data: ");
        scanf("%d",&(nn -> data));
        printf("Enter Priority: ");
        scanf("%d",&(nn -> priority));

        if(!start || (nn -> priority) < (start -> priority)){
            nn -> next = start;
            start = nn;
        }
        else {
            temp = start;
            while(temp -> next != NULL && temp -> next -> priority <= (nn -> priority))
                temp = temp -> next;
            
            nn -> next = temp -> next;
            temp -> next = nn;
        }
        temp = start;
        while(temp != NULL){
            temp = temp -> next;
            printf("%d %d", temp -> data, temp -> priority);
        }
}

void del(){
    if(!start)
        printf("No elements");
    else{
        sn *temp = start;
        printf("%d is the deleted item", start -> data);
        start = start -> next;
        free(temp);
    }
}

void display(sn *temp) {
    if (!temp)
        printf("Empty Queue");
    else {
        while(temp != NULL){
            temp = temp -> next;
            if (!(temp -> next))
                printf("%d,[priority %d]", temp -> data, temp -> priority);
            else
                printf("%d,[priority %d] -> ", temp -> data, temp -> priority);
        }
    }
}

int main(){
    int choice;
    do{
        printf("Menu:\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: {
                insert();
                break;
            }
            case 2: {
                del();
                break;
            }
            case 3: {
                display(start);
                break;
            }
            case 4: 
                exit(0);

            default: 
                printf("Invalid choice");
        }
    } while(choice != 4);
    return 0;
}