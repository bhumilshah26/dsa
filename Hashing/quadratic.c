#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int h[TABLE_SIZE] = {0};

void insert() {
    int key, index, i, hkey;
    printf("\nEnter data:\n");
    scanf("%d", &key);
    hkey = key % TABLE_SIZE;
    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + (i * i)) % TABLE_SIZE;
        if (h[index] == 0) {
            h[index] = key;
            break;
        }
    }

    if (i == TABLE_SIZE) {
        printf("\nElement cannot be inserted\n");
    }
}

void search() {
    int key, index, i, hkey;
    printf("\nEnter element to be searched:\n");
    scanf("%d", &key);
    hkey = key % TABLE_SIZE;
    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + (i * i)) % TABLE_SIZE;
        if (h[index] == key) {
            printf("Value found at index %d\n", index);
            return;
        }
    }

    printf("\nValue Not Found\n");
}

void display() {
    int i;
    printf("\nElements are \n");
    for (i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d value =  %d\n", i, h[i]);
    }
}

int main() {
    int opt;
    while (1) {
        printf("\nMenu:\n1.Insert\n2.Display\n3.Search\n4.Exit \n");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
