#include<stdio.h>
#include<stdlib.h>
#define sn struct Node

struct Node{
    int data;
    struct Node *next;
}*start;

void create(){
    int n, i, data;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    sn *nn, *temp;
    
    for(i = 0; i < n; i++){

        nn = (sn *)malloc(sizeof(sn));
        printf("Enter data: ");
        scanf("%d",&data);
        nn -> data = data;
        nn -> next = NULL;
        
        if(!start){
            start = nn;
            temp = start;
        }
        else {
            temp -> next = nn;
            temp = nn;            
        }
    }
}

void nthfromlast(int n){
    sn *temp, *temp1;
    temp = start;
    temp1 = start;
    while(n--)
        temp = temp -> next;

    while(temp){
        temp1 = temp1 -> next;
        temp = temp -> next;
    }
    printf("nth node from last %d", temp1 -> data);
}

void display(){

    sn *temp;
    temp = start;
    printf("\n");
    while(temp != NULL){
        if(temp -> next != NULL){
                printf("%d -> ",temp -> data);
            }
        else{
                printf("%d",temp -> data);
            }

        temp = temp -> next;
    }
    printf("\n");
}


int main(){
    int n;
    create();
    display();
    printf("Enter nth node number from last");
    scanf("%d", &n);
    nthfromlast(n);
    return 0;
}
