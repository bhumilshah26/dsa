#include<stdlib.h>
#include<stdio.h>

struct Node
{
   int data;
   struct Node *pre,*next;
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
        newNode -> next = NULL;

        if(start == NULL){
            start = newNode;
            newNode -> pre = NULL;
        }
        else {
            temp = start;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
            newNode -> pre = temp;
        }
    }
}

void insert_before(){
    int val, data;
    struct Node *newNode, *temp, *p; 
    printf("Enter data before which node is to be inserted: ");
    scanf("%d",&val);
    printf("Enter data:");
    scanf("%d",&data);

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = data;
    temp = start;
    while(temp -> data != val){
        p = temp;
        temp = temp -> next;
    }
    if(temp -> data == val){
        if(temp == start){
            newNode -> next = start;
            start -> pre = newNode;
            start = newNode;
        }
        else{
            while(temp -> data != val){
                p = temp;
                temp = temp -> next;
            }
            p -> next = newNode;
            newNode -> pre = p;
            newNode -> next = temp;
            temp -> pre = newNode;
        }
    }

    else 
    printf("Value not found !");
}

void insert_after(){
    int val, data;
    struct Node *newNode, *temp, *post; 
    printf("Enter data before which node is to be inserted: ");
    scanf("%d",&val);
    printf("Enter data:");
    scanf("%d",&data);

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = data;

    temp = start;
    while(temp -> data != val){
        temp = temp -> next;
    }
    post = temp -> next;
    if(temp -> data == val){
        newNode -> pre = temp;
        temp -> next = newNode;

        if(post != NULL){
        post -> pre = newNode;
        newNode -> next = post;
        }
    }

    else
    printf("Value not found !");
}

void del(){
    int val;
    printf("Enter the element to be deleted: ");
    scanf("%d",&val);

    struct Node *temp, *p, *post;
    temp = start;
    while(temp -> data != val && temp -> next != NULL){
        p = temp;
        temp = temp -> next;
    }
    post = temp -> next;
    if(temp -> data == val){
        if(temp == start){
            start = temp -> next;
            free(temp);
        }
        else{
            p -> next = post;
            post -> pre = p;
            free(temp);
        }
    }

    else
    printf("Value not found !");
}

void display(){
    struct Node *temp;
    temp = start;
    while(temp != NULL){
        if(temp -> next != NULL){
            printf("%d <--> ",temp -> data);
        }
        else{
            printf("%d",temp -> data);
        }
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
