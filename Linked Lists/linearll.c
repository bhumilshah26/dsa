#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define sn struct Node
sn {
   int data;
   sn *next;
}*start = NULL;

void create(){
    int no_of_nodes, i, data;
    printf("Enter number of nodes: ");
    scanf("%d",&no_of_nodes);
    sn *nn, *temp;
    
    for(i = 0; i < no_of_nodes; i++){
        nn = (sn *)malloc(sizeof(sn));
        printf("Enter data: ");
        scanf("%d", &data);
        nn -> data = data;
        nn -> next = NULL;
        if(start == NULL)
            start = nn; 
        else 
            temp -> next = nn;
        temp = nn;
    }
}

void insert_before(){
    int val, data;
    sn *nn, *temp, *pre; 
    printf("Enter data before which node is to be inserted: ");
    scanf("%d",&val);
    printf("Enter data:");
    scanf("%d",&data);

    nn = (sn *)malloc(sizeof(sn));
    nn -> data = data;
    temp = start;
    while(temp && temp -> data != val){
        pre = temp;
        temp = temp -> next;
    }
    if(!temp)
        printf("Value not found");
    else {
        if(temp == start)
            start = nn;
        else 
            pre -> next = nn;
        nn -> next = temp;
    }
}

void insert_after() {
    int val, data;
    sn *nn, *temp;
    printf("Enter data of to be inserted before: ");
    scanf("%d", &val);
    printf("Enter data: ");
    scanf("%d", &data);
    nn = (sn *)malloc(sizeof(sn));
    nn -> data = data;
    temp = start;
    while (temp && temp -> data != val)
        temp = temp -> next;
    if (!temp) 
        printf("Value %d not found before %d\n", val, data);
    else {
        nn -> next = temp -> next;
        temp -> next = nn;
    }
}

void del(){
    int val;
    printf("Enter to be deleted: ");
    scanf("%d", &val);
    sn *temp, *pre;
    temp = start;
    while(temp && temp -> data != val){
        pre = temp;
        temp = temp -> next;
    }
    if(!temp)
        printf("Value not found");
    else {
        if(temp == start)
            start = temp -> next;
        else 
            pre -> next = temp -> next;
        free(temp);
    }
}

void display(){
    sn *temp;
    temp = start;
    while(temp) {
        if(temp -> next != NULL)
            printf("%d -> ",temp -> data); 
        else
            printf("%d",temp -> data);
        temp = temp -> next;
    }
}

int main(){
    int i, iteration = 0;
    create();
    do
    {
        printf("\nMenu:\n");
        printf("1.Insert Before\n");
        printf("2.Insert After\n");
        printf("3.Delete\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&i);
        switch(i){
            case 1:
            insert_before();
            break;

            case 2:
            insert_after();
            break;

            case 3:
            del();
            break;

            case 4:
            display();
            break;

            case 5:
            exit(0);
            break;

            default:
            printf("Invalid Input!");
    }
    iteration++;
    }while(iteration < 8);
    return 0;
}