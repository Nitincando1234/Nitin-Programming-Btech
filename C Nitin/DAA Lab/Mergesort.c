#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>

int *a, nums;
void *generate() {
    printf("Enter the random numbers to generate: ");
    scanf("%d", &nums);
    a = (int *) malloc(sizeof(int) * nums);
    for(int i = 0; i < nums; i++) {
        a[i] = rand() % 1000;
    }
}
void *display() {
    for (int i = 0; i < nums; i++) printf("%d. %d \n", i + 1, a[i]);
}
void merge(int a[], int low, int mid, int high) {
    int *b = (int *) malloc(sizeof(int) * (high - low + 1));
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) 
            b[k++] = a[i++];
        else 
            b[k++] = a[j++];
        
    }
    if (i <= mid) {
        while (i <= mid) 
            b[k++] = a[i++]; 
        
    }
    if (j <= high) {
        while (j <= high) 
            b[k++] = a[j++];
        
    }
    for (i = low, k = 0; i <= high; i++, k++) 
        a[i] = b[k];

    free(b);
}
void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
void main() {
    clock_t st, end;
    pthread_t threads[3];
    if (pthread_create(&threads[0], NULL, generate, NULL) != 0) {
        perror("Failed to create threads !");
        exit(1);
    }
    pthread_join(threads[0], NULL);
    printf("Numbers are:\n");
    if (pthread_create(&threads[1], NULL, display, NULL) != 0) {
        perror("Failed to create threads !");
        exit(1);
    }
    pthread_join(threads[1], NULL);
    st = clock();
    mergeSort(a, 0, nums - 1);
    end = clock();
    printf("After sort:\n");
    if (pthread_create(&threads[2], NULL, display, NULL) != 0) {
        perror("Failed to create threads !");
        exit(1);
    }
    pthread_join(threads[2], NULL);
    free(a);
    printf("Time taken: %f\n", (double) (end - st) / CLOCKS_PER_SEC);
}
