#include<stdio.h>

int main(){
    int arr[] = {23, 34, 31, 35, 76, 67, 11, 39}, i = 0, j, current;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array:\n");
    while (i < size) {
        printf("%d ", arr[i++]);
    }

    for(i = 1; i < size; i++)
    {
        current = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > current){
            arr[j + 1] = arr[j];
            j--;
        }
        printf("%d\n", j + 1);
        arr[j + 1] = current;
    }

    i = 0;
    printf("\nSorted Array:\n");
    while (i < size) {
        printf("%d ", arr[i++]);
    }
    return 0;
}