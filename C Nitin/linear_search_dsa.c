#include<stdio.h>
int searchBinary(int a[],int size,int low,int high,int x){
    int mid=0;
    while (low<=high)
    {   mid=(low+high)/2;
        if(x==a[mid])
        return mid;
        else if(x>a[mid])
        low=mid+1;
        else if(x<a[mid])
        high=mid-1;

      
    }
}
int main(){
    int a[100],size,x,low,high,mid;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    printf("Enter the array elements:\n");
    for(int i=0;i<size;i++){
        printf("Enter the %dth element:",i+1);
        scanf("%d",&a[i]);
    }
    //sorting 
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size;j++){
        if(a[j]>a[j+1]){
            int temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
        }
    }
      for(int i=0;i<size;i++){
        printf("%d. %d\t",i+1,a[i]);
    }
    printf("\nEnter the element to search:");
    scanf("%d",&x);
    high=size-1;
    low=0;
    
    printf("Found at %dth position.",(searchBinary(a,size,low,high,x))+1);
      return 0;
}
