#include <stdio.h>
#include <stdlib.h>
int size, *arr;

void swap(int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selection_sort() {
    // O(n^2)
    int mid, loc;
    for (int i = 0; i < size - 1; i++) {
        mid = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[mid] > arr[j]) {
                mid = j;
            }
        }
        if (mid != i) swap(i, mid);
    }
}

void insertion_sort() {
    int temp, j = 0;
    for (int i = 0; i < size; i++){
        temp = arr[i]; j = i - 1; 
        while (j >= 0 && arr[j] >= temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void array_printer() {
    for (int i = 0; i < size; i++) printf("%d\t", arr[i]);
}

void main() {
    int choice;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    arr = (int *) malloc(sizeof(int) * size);
    printf("Enter the elements of array: \n");
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
    printf("Enter the sorting algorithm to be used: \n1. Insertion sort\n2. Selection sort: ");
    scanf("%d", &choice);
    printf("Array before sorting: \n");
    array_printer();
    if (choice == 1) insertion_sort();
    else if (choice == 2) selection_sort();
    else printf("Incorrect Choice !");
    printf("\nArray after sorting: \n");
    array_printer();
    free(arr);
}