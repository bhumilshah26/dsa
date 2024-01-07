    
#include<stdio.h>
 
int binarySearch(int arr[], int size, int element){
    int low = 0, high = size - 1, mid;
    while(low <= high){

        mid = (high + low)/2;
        if(arr[mid] > element)
            high = mid - 1;

        else if(arr[mid] < element)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}   

int main()
{

    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr)/sizeof(int), target;
    
    printf("Enter the element to be searched: ");
    scanf("%d", &target);

    int pos = binarySearch(arr, size, target);
    if(pos == -1)
    printf("Element not found");

    else 
    printf("Element is found at %d position", pos + 1);

    return 0;

}