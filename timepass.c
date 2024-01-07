#include<stdio.h>
// graph is of numbers ranging from 0 - 7
int queue[20], top = -1, front = -1, rear = -1, visited[8], stack[20];
int a[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0},        
    };
      
// BFS (Queue)
void enqueue(int val){
    queue[++rear] = val;      
}

int dequeue(){
    return queue[++front];    
}

void bfs(int source, int n){
    enqueue(source);
    printf("%d ", source);
    visited[source] = 1;
    while(front <= rear){
        int current = dequeue(); // 0
        visited[current] = 1; // visited [0] = 1
        for(int i = 0; i < n; i++){
            if(a[i][current] && !visited[i]){
                printf("%d ", i);
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    front = -1;
    rear = -1;
    for(int i = 0; i < n; i++)
        visited[i] = 0;
    printf("\n");
}

// DFS (Stack)
void push(int val){
    stack[++top] = val;
}

int pop(){
    return stack[top--];
}

void dfs(int s, int n) {
    push(s);
    visited[s] = 1;
    printf("%d ", s);

    while (top != -1) {
        int current = pop();
        for (int i = 0; i < n; i++) {
            if (a[i][current] && !visited[i]) {
                push(i);
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
    top = -1;
    for(int i = 0; i < n; i++)
        visited[i] = 0;
    printf("\n");
}

int main() {
    int n = 9, i, s, ch, j;
    char c;
    
    printf("The Adjacency Matrix is: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }

    do {
        for (i = 1; i <= n; i++)
            visited[i] = 0;
        printf("\nMenu");
        printf("\n1. BFS");
        printf("\n2. DFS");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        printf("Enter the source vertex: ");
        scanf("%d", &s);
        switch (ch) {
            case 1:
                bfs(s, n);
                break;
            case 2:
                dfs(s, n);
                break;
        }
        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &c); // Added space before %c to consume newline
    } while ((c == 'y') || (c == 'Y'));

    return 0;
}
