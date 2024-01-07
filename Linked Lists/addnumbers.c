#include<stdio.h>
#include<stdlib.h>
#define sn struct Node

struct Node{
    int data;
    struct Node *next;
}*start1 = NULL, *start2 = NULL, *start3 = NULL;

sn *create(){
    int n;
    sn *nn, *temp, *start = NULL;
    scanf("%d", &n);
    while(n){
        nn = (sn *)malloc(sizeof(sn));
        nn -> data = n % 10;
        nn -> next = NULL;
        if(!start){
            start = nn;
            temp = start;
        }
        else {
            temp -> next = nn;
            temp = nn;
        }
        n /= 10;
    }
    return start;
}

void createNode(int x){
    sn *nn, *temp;
    nn = (sn *)malloc(sizeof(sn));
    nn -> data = x;
    nn -> next = NULL;
    if(!start3)
        start3 = nn;
    else {
        temp = start3;
        while(temp -> next)
            temp = temp -> next;
        temp -> next = nn;
    }
}
void add(){
    int a = 0;
    sn *temp1 = start1, *temp2 = start2;
    while(temp2 != NULL && temp1 != NULL){
        a = a + temp1 -> data + temp2 -> data;
        createNode(a % 10);
        a /= 10;
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    // temp2 holds number less than temp1
    while(temp1){
        createNode(a + temp1 -> data);
        a /= 10;
        temp1 = temp1 -> next;
    }
    // temp1 holds number less than temp2
    while(temp2){
        createNode(a + temp2 -> data);
        a /= 10; 
        temp2 = temp2 -> next;
    }
    // for last carry generated if any
    if(a)
        createNode(a);
}

void display(sn *temp){

    while(temp){
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

    printf("Number 1: ");
    start1 = create();
    printf("\nNumber 2: ");
    start2 = create();
    display(start1);
    display(start2);
    add();
    printf("\nAdded Number\n");
    display(start3);
    return 0;
}
