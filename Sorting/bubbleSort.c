// Bubble Sort Time Complexity = O(n²)

// pehle element ko uske 
#include<stdio.h>

int main(){

    int arr[] = {23, 34, 31, 35, 76, 67, 11, 39}, temp, i = 0, j;
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted Array:\n");
    while(i < size){
        printf("%d ", arr[i++]);
    }
    for(i = 0; i < size - 1; i++){
        for(j = i + 1; j < size; j++){
            if(arr[i] > arr[j]){

                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

            }
        }
    }

    i = 0;
    printf("\nSorted Array:\n");
    while(i < size){
        printf("%d ", arr[i++]);
    }

    return 0;
}