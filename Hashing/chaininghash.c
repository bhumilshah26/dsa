#include<stdio.h>
#include<malloc.h>
#define sn struct node
#define size 10
struct node {
    int data;
    struct node *next;
}*ht[size];

int hash_function(int key) {
    return key % size;
}

void insert(int d){
    sn *nn;
    int hkey, index;
    nn = (sn *)malloc(sizeof(sn));
    nn -> data = d;
    nn -> next = NULL;
    hkey = hash_function(d);
    index = hkey % size;
    if(ht[index])
        nn -> next = ht[index];
    ht[index] = nn;
}

void display(){
    sn *temp;
    for (int i = 0; i < size; i++) {
        temp = ht[i];
        printf("%d ", i);
        while (temp != NULL) {
            printf("%d ",temp -> data);
            temp = temp -> next;
        }
        printf("\n");
    }
}

int main() {
    int x, choice;
    do {
        printf("\nMenu\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter data: ");
                scanf("%d", &x);
                insert(x);
                break;
            case 2:
                display();
                break;
            case 3:
            exit(0);
        }
    } while(choice != 3);
    return 0;
}