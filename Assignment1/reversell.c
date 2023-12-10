#include <stdio.h>
#include <stdlib.h>

#define sn struct Node

struct Node {
    int data;
    struct Node *next;
} *start;


void create() {
    int no_of_nodes, i, data;
    printf("Enter number of nodes: ");
    scanf("%d", &no_of_nodes);
    sn *newNode, *temp;

    for (i = 0; i < no_of_nodes; i++) {
        newNode = (sn *)malloc(sizeof(sn));
        printf("Enter data: ");
        scanf("%d", &data);
        newNode -> data = data;
        newNode -> next = NULL;

        if (!start) {
            start = newNode;
            temp = start;
        } else {
            temp -> next = newNode;
            temp = temp -> next;
        }
    }
}

// void reverse(sn *pre, sn *current) {
//     sn *post;
//     post = current -> next;
//     if(pre == start)
//     pre -> next = NULL;
//     if(current){
//     current -> next = pre;

//     if (!post) {
//         start = current;
//     } 
//     else {
//         reverse(current, post);
//     }
//     }
//     else{
//         printf("Only One Node");
//     }
// }
void reverse(sn *pre, sn *current) {
    if (!current) {
        printf("\nOnly One Node");
        return;
    }
    else {
        sn *post = current->next;

        if (pre == start)
            pre->next = NULL;

        if (current) {
            current -> next = pre;

            if (!post) 
                start = current;
            else
                reverse(current, post);
        }
    }
}

// struct Node* reverseRecursively(struct Node* head) {
//     if (head->next == NULL) {
//         return head;
//     }

//     struct Node* rest = reverseRecursively(head->next);
//     head->next->next = head;
//     head->next = NULL;
//     return rest;
// }


void display(sn *temp) {
    if(start != NULL){
    if (!temp);
    else {
        if (!temp -> next)
        printf("%d", temp -> data);
        else
        printf("%d -> ", temp -> data);
        display(temp -> next);
    }
    }
    else
    printf("List Empty");
}

int main() {
    create();
    printf("Original LL\n");
    display(start);
    reverse(start, start -> next);
    printf("\nReversed LL\n");
    display(start);

    return 0;  
}
