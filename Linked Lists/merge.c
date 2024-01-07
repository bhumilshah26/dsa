#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
}*start1, *start2;

struct Node* create(){

    int i, no_of_nodes, data;
    struct Node* newNode, * temp, * start = NULL; // start = NULL karna ati aavashyak h program aage nhi badhega
    printf("Enter the number of nodes: ");
    scanf("%d",&no_of_nodes);
    for(i = 0; i < no_of_nodes; i++){

        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d",&data);
        newNode -> data = data;
        newNode -> next = NULL;

        if(start == NULL){
            start = newNode;
            temp = start;
        }
        else 
        {
            temp -> next = newNode;
            temp = newNode;
        }
    }
    return start;

}

struct Node* merge(){

    struct Node *temp = NULL;
    temp = start1;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = start2;

    return start1;
}

void display(struct Node* temp) {

    while (temp != NULL) {
        if(temp -> next != NULL)
        printf("%d -> ", temp -> data);

        else
        printf("%d", temp -> data);

        temp = temp -> next;
    }

}

int main(){
    printf("List 1: \n");
    start1 = create();
    printf("List 2: \n");
    start2 = create();
    printf("\nLinked list 1: ");
    display(start1);
    printf("\nLinked list 2: ");
    display(start2);
    start1 = merge();
    printf("\nMerged list: ");
    display(start1);

}