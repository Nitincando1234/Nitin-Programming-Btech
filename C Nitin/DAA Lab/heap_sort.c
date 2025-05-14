#include <stdio.h>
#include <stdlib.h>

void heapify(int *a, int size, int i) {
    int largest = i, l = (2 * i) + 1, r = (2 * i) + 2;
    if(l < size && a[l] > a[largest]) largest = l;
    if(r < size && a[r] > a[largest]) largest = r;
    if(largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, size, largest);
    }
}

void heapsort(int *a, int size) {
    for(int i = size / 2 - 1; i >= 0; i--)
        heapify(a, size, i);
    for(int i = size - 1; i > 0; i--){
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}

void main() {
    int *a, size;
    printf("Enter the size of the array: "); scanf("%d", &size);
    a = (int *) malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    heapsort(a, size);
    printf("\nAfter sorting the elements of array: \n");
    for(int i = 0; i < size; i++) printf("%d ", a[i]);
    free(a);
}