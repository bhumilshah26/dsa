#include<stdio.h>

int a[10];

void display(int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int pivot(int lb, int ub) {
    int start = lb, end = ub, pivot = a[lb], temp;
    while (start < end) {
        while (a[start] <= pivot)
            start++;

        while(a[end] > pivot)
            end--;

        if(start < end){
            temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }        
    }
    temp = a[end];
    a[end] = a[lb];
    a[lb] = temp;
    return end;
}

void quickSort(int low, int high) {
    if (low < high) {
        int pi = pivot(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int main() {
    int n, i = 0;
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    while(i < n){
        printf("Enter integer: ");
        scanf("%d", &a[i]);
        i++;
    }
    display(n);
    printf("Sorted Array\n");
    quickSort(0, n - 1);
    display(n);
    return 0;
}
