#include<time.h>
#include<stdio.h>
#include<stdlib.h>

void quickSort(int nums[], int low, int high) {
    int i, j, key;
    key = low; i = low + 1; j = high;
    if(low >= high) return;
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
    int a[100000], nums;
    clock_t st, ed;
    printf("Enter the numbers you want to sort: ");
    scanf("%d", &nums);
    printf("The random numbers generated are:\n ");
    for(int i = 0; i < nums; i++) {
        a[i] = rand();
        printf("%d. %d\n", i + 1, a[i]);
    }
    st = clock();
    quickSort(a, 0, nums - 1);
    ed = clock();
    printf("The numbers after sortingL:\n");
    for(int i = 0; i < nums; i++ ) {
        printf("%d. %d\n", i + 1, a[i]);
    }
    printf("\nThe sorting is completed ! The time required was: %f\n", (double)(ed - st) / CLOCKS_PER_SEC);
}