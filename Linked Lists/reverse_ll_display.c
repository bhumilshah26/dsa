#include<stdio.h>
#include<stdlib.h>
#define sn struct Node

struct Node {
   int data;
   sn *next;
}*start;

void create(){
    int no_of_nodes, i, data;
    printf("Enter number of nodes: ");
    scanf("%d", &no_of_nodes);
    sn *nn, *temp;
    
    for(i = 0; i < no_of_nodes; i++){

        nn = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d",&data);
        nn -> data = data;
        nn -> next = NULL;
        
        if(start == NULL)
            start = nn;
        else {
            temp = start;
            while(temp -> next != NULL)
                temp = temp -> next;

            temp -> next = nn;
        }
    }
}

void display_reverse(sn *temp) {
    if(!(temp -> next));
    
    else
        display_reverse(temp -> next);

    printf("%d ", temp -> data);
}

void reverse_ll(sn *temp){
    sn *pre;
    pre = temp;
    temp = temp -> next;
    if(temp -> next == NULL)
        start = temp;
       
    else {
        if(pre == start)
            pre -> next = NULL;
        reverse_ll(temp);
    }
    temp -> next = pre;
}

void display(){

    struct Node *temp;
    temp = start;
    while(temp != NULL){
        if(temp -> next != NULL)
            printf("%d -> ",temp -> data);
            
        else
            printf("%d",temp -> data);

        temp = temp -> next;
    }
}

int main(){
    create();
    printf("Reversing display: ");
    display_reverse(start);
    printf("\nReversing Linked List: ");
    reverse_ll(start);
    display();
}