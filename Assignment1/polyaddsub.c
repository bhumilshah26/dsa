#include<stdio.h>
#include<stdlib.h>
#define sn struct Node

struct Node{
    int p, c;
    struct Node *next;
}*start1 = NULL, *start2 = NULL, *start3 = NULL;

sn * create(){
    int n, i;
    sn *nn, *temp, *start = NULL;
    printf("Enter the number of terms:");
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        nn = (sn *)malloc(sizeof(sn));
        nn -> next = NULL;
        printf("Enter power: ");
        scanf("%d",&(nn -> p));
        printf("Enter Coefficient: ");
        scanf("%d",&(nn -> c));
        if(!start){
            start = nn;
            temp = start;
        }
        else{
            temp -> next = nn;
            temp = nn;
        }
    }
    return start;
}

void link(int c, int p){

    sn *nn, *temp;
    nn = (sn *)malloc(sizeof(sn));
    temp = start3;

    nn -> c = c;
    nn -> p = p;
    nn -> next = NULL;
    if(start3 == NULL)
        start3 = nn;
    else {
        while(temp -> next != NULL)
            temp = temp -> next;
        temp -> next = nn;
    }
}
void subtract();
void addition(){

    int c, p;
    sn *temp, *temp1;
    temp = start1;
    temp1 = start2;
    while(temp != NULL && temp1 != NULL){
        if(temp -> p > temp1 -> p){
            c = temp -> c;
            p = temp -> p; 
            temp = temp -> next;
        }
        else if(temp -> p < temp1 -> p){
            c = temp1 -> c;
            p = temp1 -> p;
            temp1 = temp1 -> next;
        }
        else {
            c = temp -> c + temp1 -> c;
            p = temp -> p;
            temp = temp -> next;
            temp1 = temp1 -> next;
        }
        link(c, p);
    }

    while(temp){
        c = temp -> c;
        p = temp -> p;
        temp = temp -> next;
        link(c, p);
    }

    while(temp1){
        c = temp1 -> c;
        p = temp1 -> p;
        temp1 = temp1 -> next;
        link(c, p);
    }
}

void display(sn *temp){
    while(temp != NULL){
        if(temp -> next != NULL){
                printf("C:%d, P:%d -> ",temp -> c, temp -> p);
            }
        else{
                printf("C:%d, P:%d",temp -> c, temp -> p);
            }

        temp = temp -> next;
    }
    printf("\n");
}

int main(){

    printf("List 1:\n");
    start1 = create();
    printf("List 2:\n");
    start2 = create();
    printf("List 1:\n");
    display(start1);
    printf("List 2:\n");
    display(start2);
    addition();
    printf("Addition:\n");
    display(start3);
    start3 = NULL;
    subtract();
    printf("Subtraction:\n");
    display(start3);
    return 0;
}
void subtract(){

    int c, p;
    sn *temp, *temp1;
    temp = start1;
    temp1 = start2;
    while(temp != NULL && temp1 != NULL){
        if(temp -> p > temp1 -> p){
            c = temp -> c;
            p = temp -> p; 
            temp = temp -> next;
        }
        else if(temp -> p < temp1 -> p){
            c = temp1 -> c;
            p = temp1 -> p;
            temp1 = temp1 -> next;
        }
        else {
            c = temp -> c - temp1 -> c;
            p = temp -> p;
            temp = temp -> next;
            temp1 = temp1 -> next;
        }
        link(c, p);
    }

    while(temp){
        c = temp -> c;
        p = temp -> p;
        link(c, p);
        temp = temp -> next;
    }

    while(temp1){
        c = temp1 -> c;
        p = temp1 -> p;
        temp1 = temp1 -> next;
        link(c, p);
    }
}
