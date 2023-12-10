#include<stdlib.h>
#include<stdio.h>

struct Node
{
   int data;
   struct Node *next;
}*start;

void create(){
    int no_of_nodes, i, data;
    printf("Enter number of nodes: ");
    scanf("%d",&no_of_nodes);
    struct Node *newNode, *temp;
    for(i = 0; i < no_of_nodes; i++){

        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d",&data);
        newNode -> data = data;
        
        if(start == NULL){
            start = newNode;
            newNode -> next = start;
        }
        else {
            temp = start;
            while(temp -> next != start){
                temp = temp -> next;
            }
            temp -> next = newNode;
            newNode -> next = start;
        }
    }
}

void insert_before(){
    int val, data;
    struct Node *newNode, *temp, *p; 
    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data before which node is to be inserted: ");
    scanf("%d",&val);
    printf("Enter data: ");
    scanf("%d",&data);
    newNode -> data = data;
    temp = start;
    while(temp -> data != val && temp -> next != start){
        temp = temp -> next;
    }
    if(temp -> data == val){
        if(temp == start){
        p = start;
        while(p -> next != start){
            p = p -> next;
        }
        newNode -> next = start;
        start = newNode;
        p -> next = newNode;
        }
        else{
            temp = start;
            while(temp -> data != val){
                p = temp;
                temp = temp -> next;  
            }
            p -> next = newNode;
            newNode -> next = temp;
        }
    }
    else 
    printf("Value not found !");
}

void insert_after(){
    int val, data;
    struct Node *newNode, *temp; 
    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data after which node is to be inserted: ");
    scanf("%d",&val);
    printf("Enter data: ");
    scanf("%d",&data);

    newNode -> data = data;
    temp = start;

    while(temp -> data != val && temp -> next != start){
        temp = temp -> next;  
    }
    if(temp -> data == val){
    newNode -> next = temp -> next;
    temp -> next = newNode;
    }

    else
    printf("Value not found !");
}

void del(){
    int val;
    struct Node *temp, *temp1, *pre;
    printf("Enter the data to be deleted: ");
    scanf("%d",&val);
    temp = start;
    while(temp -> data != val && temp -> next != start){
        pre = temp;
        temp = temp -> next;
    }
    if(temp -> data == val){
        if(temp == start){
        temp1 = start;
        while(temp1 -> next != start){
            temp1 = temp1 -> next;
        }
        temp1 -> next = temp -> next;
        start = temp -> next;
        free(temp);
        }
        else{
            pre -> next = temp -> next;
            free(temp);
        }   
    }
    else 
    printf("Value not found !");
}

void display(){
    struct Node *temp;
    temp = start;
    while(temp -> next != start){
        printf("%d -> ",temp -> data);
        temp = temp -> next;
    }
    printf("%d -> %d", temp -> data, start -> data);
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