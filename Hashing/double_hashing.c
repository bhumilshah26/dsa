#include<stdio.h>
#define size 10
#define size2 8
int ht[10] = {0};

int hash_function(int x){
    return x % size;
}

int hash_function2(int x) {
    return x % size2;
}

void insert(int d){
    int hkey = hash_function(d), index, hf2 = hash_function2(d);
    for(int i = 0; i < size; i++){
        index = (hkey + i * hf2) % size;
        if(!ht[index]){
            ht[index] = d;
            break;
        }
    }
}

void linear_search(int x) {
    int i, hkey = hash_function(x), index, hf2 = hash_function2(x);
    for(i = 0; i < size; i++){
        index = (hkey + i * hf2) % size;
        if(ht[index] == x){
            printf("Value %d found at index %d", x, index);
            break;
        }
    }
    if(i == size)
        printf("Value not found!");
}

void display() {
    int i;
    printf("\nElements are \n");
    for (i = 0; i < size; i++) {
        printf("\nIndex %d value = %d", i, ht[i]);
    }
    printf("\n");
}

int main() {
    int choice, key;
    do{
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &key);
                linear_search(key);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
        }
    } while (choice != 4);    
    return 0;
}