#include<stdio.h>
#include<stdlib.h>
#define sn struct Node

struct Node {
    int value;
    struct Node *next;
} *start1, *start2;

void display(sn *temp) {
    if (!temp);
    else {
        if (!temp -> next)
        printf("%d", temp -> value);
        else
        printf("%d -> ", temp -> value);
        display(temp -> next);


    }
}
sn *create(){
    int n, i, data;
    sn *nn, *temp, *start = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        nn = (sn *)malloc(sizeof(sn));
        printf("Enter data: ");
        scanf("%d", &data);
        nn -> value = data;
        nn -> next = NULL;

        if (!start) {
            start = nn;
            temp = start;
        } 
        else {
            temp -> next = nn;
            temp = temp -> next;
        }
    }
    return start;
}

void merge(){
    sn *temp = start1;
    while(temp -> next){
        temp = temp -> next;
    }
    temp -> next = start2;
    printf("\nLinked List 3:\n");
    display(start1);
}
// based on number of node
void demerge(){
    int n;
    sn *temp = start1;
    printf("Enter the number of node");
    scanf("%d", &n);
    while(--n){
        temp = temp -> next;
    }
    start2 = temp -> next;
    temp -> next = NULL;
    printf("\nLinked List 4:\n");
    display(start1);
    printf("\nLinked List 5:\n");
    display(start2);

}

// Based on value
void demerge1(){
    int val;
    sn *temp = start1;
    printf("Enter the value value:");
    scanf("%d", &val);
    while(temp && temp -> value != val)
        temp = temp -> next;
    if(temp){
        start2 = temp -> next;
        temp -> next = NULL;
        printf("\nLinked List 4:\n");
        display(start1);
        printf("\nLinked List 5:\n");
        display(start2);
    }
    else
    printf("Value Not Found");
}

int main(){
    
    start1 = create();
    start2 = create();
    printf("Linked List 1:\n");
    display(start1);
    printf("\nLinked List 2:\n");
    display(start2);
    merge();
    demerge1();  // change this as per requirement  
    return 0;

}
