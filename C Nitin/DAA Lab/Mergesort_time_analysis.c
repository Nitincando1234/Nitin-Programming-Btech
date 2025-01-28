#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *a, nums = 100000, count;
void generate(int count) {
    a = (int *) malloc(sizeof(int) * count);
    srand(time(0));
    for(int i = 0; i < count; i++) {
        a[i] = rand();
    }
}
void merge(int a[], int low, int mid, int high) {
    int b[count];
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (a[i] >= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if (i < mid) {
        while (i <= mid) {
            b[k] = a[i]; i++;
        } k++;
    }
    if (j < high) {
        while (j <= high) {
            b[k] = a[j]; j++;
        } k++;
    }
}
void mergeSort(int a[], int low, int high) {
    int mid = (low + high) / 2;
    if (low < high) {
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
void main() {
    clock_t st, end;
    int steps = 5000;

    for (count = 0; count < nums; count += steps) {
    generate(count);
    st = clock();
    mergeSort(a, 0, count - 1);
    end = clock();
    free(a);
    printf("%d. Time taken: %f\n",(count / steps), (double) (end - st) / CLOCKS_PER_SEC);
    }

}