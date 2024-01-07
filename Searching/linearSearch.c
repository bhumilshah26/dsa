// Linear Search Time Complexity = O(n)

#include<stdio.h>

int linearSearch(int arr[], int size, int element){

    for(int i = 0; i < size; i++){
        if(arr[i] == element)
        return i;
    }
    return -1;

}
int main(){

    int arr[] = {12, 33, 22, 45, 67, 1, 56}, target, size = sizeof(arr)/sizeof(arr[0]);

    printf("Enter the element to be searched: ");
    scanf("%d", &target);

    int pos = linearSearch(arr, size, target);

    if(pos == -1)
    printf("Element not found");

    else
    printf("Element is found at %d position", pos + 1);
    

}