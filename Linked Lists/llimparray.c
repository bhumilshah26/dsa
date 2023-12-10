#include<stdio.h>
#include<conio.h>
#define Size 5
struct Node
{
    int data;
    struct Node *next;
}*start;

void create(int s){
    struct Node *newNode, *temp;
    int val, i;
    for(i = 0; i < s; i++)
    {
        printf("Enter the data: ");
        scanf("%d",&val);
        newNode -> data = val;
        newNode -> next = NULL;
        if(start == NULL){
            start = newNode;
            temp = newNode;
        }
        else {
            temp -> next = newNode;
            temp = newNode;
        }
    }
}

void insert(){
    
}