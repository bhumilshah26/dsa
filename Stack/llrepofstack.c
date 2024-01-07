#include<stdio.h>
#include<stdlib.h>
#define sn struct Node
struct Node{
    int data;
    struct Node *next;
}*top;

void push(int val){ 
    sn *nn;
    nn = (sn *)malloc(sizeof(sn));
    nn -> data = val;
    nn -> next = top;
    top = nn;
}

int pop(){

    int x;
    struct Node *temp;
    temp = top;
    top = temp -> next;
    x = temp -> data;
    free(temp);

    return x;
}

void peek(){
    printf("%d ",top -> data);
}

void display(){

    struct Node *temp;
    temp = top;
    while(temp != NULL){
        if(temp -> next != NULL)
        {
        printf("%d -> ", temp -> data);
        }
        else{
        printf("%d", temp -> data);
        }
        temp =  temp -> next;
    }

}

int main(){
    int j;
    do
    {
       printf("\nMenu:\n");
       printf("1.Push\n");
       printf("2.Pop\n");
       printf("3.Peek\n");
       printf("4.Display\n");
       printf("5.Exit\n");
       printf("Enter the choice: ");
       scanf("%d",&j);
       switch (j)
       {
       case 1:
        printf("Enter the value: ");
        scanf("%d",&j);
        push(j);
        break;

        case 2:
        j = pop();
        printf("%d is deleted", j);
        break;

        case 3:
        peek();
        break;

        case 4:
        display();
        break;

        case 5:
        exit(0);

        default:
        printf("Inavlid Input!");
       }

    } while (j != 5);
    
    return 0;
}