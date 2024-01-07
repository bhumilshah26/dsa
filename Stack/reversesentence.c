#include<stdlib.h>
#include<stdio.h>

#define size 100
char sentence[size];
char word[10];
char stack[50];
int top = -1;

void push(char a){
    stack[++top] = a;
}

char pop(){
    return stack[top--];
}


void reverse(){

    int i = 0, j;
    while(sentence[i] != '\0'){
        word[0] = ' ';
        j = 1;
        while(sentence[i] != '\0' && sentence[i] != ' ')
            word[j++] = sentence[i++];
        
        while(j != -1)
            push(word[--j]);
        i++;
    }
}

void display(){
    for(int i = top; i != -1; i--)
        printf("%c", stack[i]);
}

int main(){

    printf("Enter the sentence: ");
    scanf("%[^\n]s",sentence);
    printf("Original Sentence: %s\n", sentence);
    printf("Reversed Sentence:");
    reverse();
    display();

    return 0;

}