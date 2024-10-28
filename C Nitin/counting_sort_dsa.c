#include<stdio.h>
void count_sort(int a[],int n,int k){
    int count[k],b[n];
    for(int i=0;i<k;i++){
        count[i]=0;
    }
    for(int i=0;i<k;i++){
        ++count[a[i]];
    }
    for(int i=1;i<k;i++){
        count[i]=count[i]+count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        b[--count[a[i]]]=a[i];
    }
    for(int i=0;i<n;i++){
        printf("%d\n",b[i]);
    }}
void main(){
    printf("Enter the size and range of the input data: ");
    int k,n;
    scanf("%d",&n);
    scanf("%d",&k);
    int a[10];
    for(int i=0;i<n;i++){
        printf("Enter the %dth Element: ",i+1);
        scanf("%d",&a[i]);
    }
    count_sort(a,n,k);
}