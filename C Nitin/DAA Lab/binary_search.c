#include <stdio.h>

void main() {
    int size, search_term, flag = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the array elements: ");
    int arr[size], lo = 0, hi = size - 1, mid = 0;
    for(int i = 0; i < size; i++) 
        scanf("%d", &arr[i]);
    printf("Enter the element to search in the array: ");
    scanf("%d", &search_term);
    printf("Searching for the %d in array: \n", search_term);
    while(lo <= hi) {
        mid = (lo + hi) / 2;
        if(arr[mid] == search_term) {
            printf("Found at index: %d!\n", mid); flag = 1;
            printf("Completed !\n");
            return;
        }
        else if(arr[mid] < search_term) lo = mid + 1;
        else hi = mid - 1;
    }
    if(flag == 0) printf("Not Found\n");
    printf("Completed !\n");
}