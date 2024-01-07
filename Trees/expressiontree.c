#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>
#define sn struct node

char postfix[100];
sn *stack1[10];
int top1 = -1;

struct node{
    char a;
    sn *left, *right;
} *root;

void push1(sn *nn){
    if(!root)
    root = nn;

    top1++;
    stack1[top1] = nn;
    
}

sn *pop1(){
    sn *temp;
    if(top1 == -1){
        root = NULL;
        temp = NULL;
    }
    else {
        temp = stack1[top1];
        top1--;
    }
        return temp;
}


void create(char x){
    sn *nn;
    nn = (sn *)malloc(sizeof(sn));
    nn -> a = x;
    nn -> left = nn -> right = NULL;
    push1(nn);
    root = nn;
}

void createNode(char x){

    sn *nn, *temp;
    nn = (sn *)malloc(sizeof(sn));
    nn -> a = x;
    temp = pop1();
    nn -> right = temp;
    temp = pop1();
    nn -> left = temp;
    push1(nn);
    root = nn;

}

void expression_tree() {
    int i = 0;
    char x;

    while(postfix[i] != '\0'){
        x = postfix[i];
        if(isalnum(x))
            create(x);
        
        else if(x == '+' || x == '-' || x == '*' || x == '/' || x == '%')
            createNode(x);

        else {
            printf("Expression incorrect");
            break;
        }
        i++;
    }    
}

void inorder(sn *temp){
    if (temp) {
        inorder(temp -> left);
        printf("%c ", temp -> a);
        inorder(temp -> right);
    }
}

int main(){

    printf("Enter the Postfix expression:\n");
    scanf("%s", postfix);
    expression_tree();
    inorder(root);
    return 0;

}