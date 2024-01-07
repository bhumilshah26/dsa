#include<stdio.h>
#include<conio.h>
#define size 10
int data[10] = {0}, priority[10] = {__INT_MAX__};

int minpriority(int p) {
    int i = 0;
    while(priority[i] <= p) {
        printf("$");
        i++;
    }
    return i;
}

void rotateright(int i) {
    if(i == size - 2){}

    else {
        rotateright(++i);
    }

    data[i + 1] = data[i];
    priority[i + 1] = priority[i];
} 

void rotateleft() {
    int i = 0;
    for(; i < size - 1; i++) {
        data[i] = data[i + 1];
        priority[i] = priority[i + 1];
    }
    data[i] = 0;
    priority[i] = __INT_MAX__;
}

void insert() {
    int d, p, i;
    printf("Enter the data: ");
    scanf("%d", &d);
    printf("Enter the priority: ");
    scanf("%d", &p);
    i = minpriority(p);
    rotateright(i);
    data[i] = d;
    priority[i] = p;
}

void del() {
    printf("Data: %d Priority: %d is deleted", data[0], priority[0]);
    rotateleft();
}

void display() {
    for(int i = 0; priority[i] != __INT_MAX__; i++) 
        printf("Data %d Priority %d", data[i], priority[i]);
}

int main() {
    int choice;
    do{
        printf("Menu:\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: {
                insert();
                break;
            }
            case 2: {
                del();
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: 
                exit(0);

            default: 
                printf("Invalid choice");
        }
    } while(choice != 4);
    return  0;
}