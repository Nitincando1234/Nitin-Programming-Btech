#include<time.h>
#include<stdio.h>
#include<stdlib.h>

void quickSort(int nums[], int low, int high) {
    if(low >= high) return;
    int i, j, key;
    key = low; i = low + 1; j = high;
    while(i <= j) {
        while(i <= high && nums[i] <= nums[key]) i += 1;
        while(j > low && nums[j] > nums[key]) j -= 1;
        if(i < j) {
            int temp = nums[i];
            nums[i] = nums[j]; nums[j] = temp;
        }
    }
    int temp = nums[key];
    nums[key] = nums[j]; nums[j] = temp;
    quickSort(nums, low, j - 1);
    quickSort(nums, j + 1, high);
}

void main() {
    int *a, nums = 100000, steps = 5000;
    clock_t st, ed;
    for(int count = 0; count <= nums; count += steps){  
    a = (int *)malloc(sizeof(int) * count);
    srand(time(0));
    for(int i = 0; i < count; i++)
        a[i] = rand();
    st = clock();
    quickSort(a, 0, count - 1);
    ed = clock();
    printf("\n%d (%d): %f\n", count / steps, count, (double)(ed - st) / CLOCKS_PER_SEC);
    free(a);
    }
}
