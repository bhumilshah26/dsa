// Selection Sort Time Complexity = O(n²)

#include<stdio.h>

int main() {

    int arr[] = {23, 34, 31, 35, 76, 67, 11, 39}, i = 0, j, min, temp;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array:\n");
    while (i < size) {
        printf("%d ", arr[i++]);
    }
    for (i = 0; i < size - 1; i++) 
    {
        min = i;                            
        for (j = i + 1; j < size; j++) {
            if (arr[min] > arr[j]) 
                min = j;
            
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

    }

    i = 0;
    printf("\nSorted Array:\n");
    while (i < size) {
        printf("%d ", arr[i++]);
    }

    return 0;
}
