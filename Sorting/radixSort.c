// Radix Sort Time Complexity = O(n²)


#include<stdio.h>

int getMax(int arr[], int n){
    int i, max = arr[0];

    for(i = 1; i < n; i++){
        if(max < arr[i])
        max = arr[i];
    }

    return max;
}

void countSort(int arr[], int n, int pos){
    int i, count[10] = {0}, b[n];

    // increment the count array based on the position of numbers
    for(i = 0; i < n; i++){ // n 
        ++count[(arr[i]/pos) % 10];
    }
    // updating the count array
    for(i = 1; i < 10; i++){
        count[i] += count[i - 1]; 
    }

    // main sorting (always start from the last element in the array)
    for(i = n - 1; i >= 0; i--){
        b[--count[(arr[i]/pos) % 10]] = arr[i];
    }
    // same array ko update karna
    for(i = 0; i < n; i++){
        arr[i] = b[i];
    }

}
void radixSort(int arr[], int n){ 
    int pos, max = getMax(arr, n);
    for(pos = 1; max/pos > 0; pos = pos * 10){  //ye mat bhulna
        countSort(arr, n, pos);
    }
}

int main(){
    int arr[] = {432, 8, 530, 90, 88, 231, 11, 45, 677, 199, 234, 120}, i = 0;
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted Array:\n");
    while(i < size){
        printf("%d ", arr[i++]);
    }
    radixSort(arr, size);
    printf("\nSorted Array:\n");
    i = 0;
    while(i < size){
        printf("%d ", arr[i++]);
    }
}