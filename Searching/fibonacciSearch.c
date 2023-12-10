#include <stdio.h>
int min(int x, int y) {
    return (x <= y) ? x : y;
}

int fibonacciSearch(int arr[], int x, int n) {
    int fibMminus2 = 0; 
    int fibMminus1 = 1; 
    int fibM = fibMminus1 + fibMminus2;  // 1
    int offset = -1;

    while (fibM < n) {
        fibMminus2 = fibMminus1;
        fibMminus1 = fibM;
        fibM = fibMminus1 + fibMminus2;
    }


    while (fibM > 1) {
        
        int i = min(offset + fibMminus2, n - 1);

        if (arr[i] < x) {
            fibM = fibMminus1;
            fibMminus1 = fibMminus2;
            fibMminus2 = fibM - fibMminus1;
            offset = i;
        }

        else if (arr[i] > x) {
            fibM = fibMminus2;
            fibMminus1 = fibMminus1 - fibMminus2;
            fibMminus2 = fibM - fibMminus1;
        }

        else
            return i;
    }

    if (fibMminus1 && arr[offset + 1] == x)
        return offset + 1;

    return -1;
}

int main() {
    int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 85;

    int result = fibonacciSearch(arr, x, n);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
