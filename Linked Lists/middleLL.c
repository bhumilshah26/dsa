#include<stdio.h>
#include<stdlib.h>
# define sn struct Node

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
        
        if(start == NULL){
            start = nn;
        }
        else {
            temp = start;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = nn;
        }
    }
}

void display(){

    sn *temp;
    temp = start;
    printf("\n");
    while(temp != NULL){
        if(temp -> next != NULL){
                printf("%d -> ", temp -> data);
            }
        else{
                printf("%d", temp -> data);
            }

        temp = temp -> next;
    }
    printf("\n");
}

void middle(){
    sn *temp = start, *temp1 = start;
    while(temp1 && temp1 -> next){
        temp = temp -> next;
        temp1 = temp1 -> next -> next;
    }
    printf("\n%d is the middle", temp -> data);
}

int main(){
    create();
    display();
    middle();
    return 0;
}