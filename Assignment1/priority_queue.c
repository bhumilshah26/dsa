#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define sn struct Node

struct Node {
    int data, priority;
    sn *next;
}*start = NULL;

void insert(){
    sn *nn, *temp, *pre;
    nn = (sn*)malloc(sizeof(sn));
    int d, p;
    printf("Enter the data: ");
    scanf("%d", &d);
    printf("Enter the priority: ");
    scanf("%d", &p);
    nn -> data = d;
    nn -> priority = p;
    if(!start || (nn -> priority < start -> priority)){
        nn -> next = start;
        start = nn;
    }
    else {
        temp = start;
        while(temp != NULL && temp -> priority <= p){
            pre = temp;
            temp = temp -> next;
        }
            pre -> next = nn;
            nn -> next = temp; 
    }
}

void del(){
    if(!start)
        printf("No elements!");
    else {
        sn *temp = start;
        printf("Deleted element: %d", temp -> data);
        start = temp -> next;
        free(temp);
    }
}

void display() {
    sn *temp = start;
    while(temp) {
        printf("Data: %d Priority: %d\n",temp -> data, temp -> priority);
        temp = temp -> next;
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
                display();
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