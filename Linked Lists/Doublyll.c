#include<stdlib.h>
#include<stdio.h>
#define sn struct Node
sn {
   int data;
   sn *pre,*next;
}*start = NULL;

void create(){
    int no_of_nodes, i, data;
    printf("Enter number of nodes: ");
    scanf("%d", &no_of_nodes);
    sn *nn, *temp;
    for(i = 0; i < no_of_nodes; i++){
        nn = (sn *)malloc(sizeof(sn));
        printf("Enter data: ");
        scanf("%d",&data);
        nn -> data = data;
        nn -> pre = nn -> next = NULL;
        if(!start)
            start = nn;
        else {
            temp -> next = nn;
            nn -> pre = temp;
        }
            temp = nn;
    }
}

void insert_before(){
    int val, data;
    sn *nn, *temp; 
    printf("Enter data before which node is to be inserted: ");
    scanf("%d", &val);
    printf("Enter data:");
    scanf("%d", &data);

    nn = (sn *)malloc(sizeof(sn));
    nn -> data = data;
    nn -> pre = nn -> next = NULL;
    temp = start;
    while(temp && temp -> data != val)
        temp = temp -> next;
    
    if(!temp)
        printf("Value not found !");
    else {
        if(temp == start)
            start = nn;
        else {
            temp -> pre -> next = nn;
            nn -> pre = temp -> pre;
            temp -> pre = nn;
        }
        nn -> next = temp;
    }
}

void insert_after(){
    int val, data;
    sn *nn, *temp; 
    printf("Enter data after which node is to be inserted: ");
    scanf("%d", &val);
    printf("Enter data:");
    scanf("%d", &data);

    nn = (sn *)malloc(sizeof(sn));
    nn -> data = data;
    nn -> pre = nn -> next = NULL;
    temp = start;
    while(temp && temp -> data != val) 
        temp = temp -> next;
    if(!temp)
        printf("Value not found");
    else {
        if(temp -> next){
            temp -> next -> pre = nn;
            nn -> next = temp -> next;
        }
        temp -> next = nn;
        nn -> pre = temp;
    }
}

void del(){
    int val;
    printf("Enter the element to be deleted: ");
    scanf("%d", &val);
    sn *temp;
    temp = start;

    while(temp && temp -> data != val)
        temp = temp -> next;

    if(!temp)
        printf("Value not found");
    else {
        if(temp == start)
            start = temp -> next;
        else {
            if(temp -> next){
                temp -> pre -> next = temp -> next;
                temp -> next -> pre = temp -> pre;
            }
            else
                temp -> pre -> next = NULL;  
        }
        free(temp);
    }
}

void display(){
    sn *temp;
    temp = start;
    while(temp){
        if(temp -> next)
            printf("%d <--> ",temp -> data);
        else
            printf("%d",temp -> data);
        temp = temp -> next;
    }
}

int main(){
    int i, iteration = 0;
    create();
    do {
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