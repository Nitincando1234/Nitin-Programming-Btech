#include <stdio.h>
int a[100];
void print(int a[],int size){
    for(int i=0;i<size;i++){
    printf("\n%dth element: %d",i+1,a[i]);}
}
void selection_sort(int a[],int size)
{int min,loc;
for(int i=0;i<size;i++){
    min=a[i];
    
    for(int j=i+1;j<size;j++){
        if(min>a[j]){
            min=a[j];
            loc=j;
        }
        }
    int temp=a[i];
    a[i]=a[loc];
    a[loc]=temp;
    }
    for(int i=0;i<size;i++){
        printf("\n%dth element: %d",i+1,a[i]);
    }
}
void insertion_sort(int a[],int size){
for(int i=0;i<size;i++)
{
    int temp=a[i];
    int j=i-1;
    while(a[j]>temp && j>=0){
        a[j+1]=a[j];j--;
    }
    a[j+1]=temp;
}for(int i=0;i<size;i++){
    printf("\n%dth element: %d",i+1,a[i]);}
}
void bubble_sort(int a[],int size){
    for(int i=0;i<size-1;i++){
    for(int j=0;j<size-i-1;j++){
    if(a[j]>a[j+1]){
        int temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
    }
    }
    }
    for(int i=0;i<size;i++){
    printf("\n%dth element: %d",i+1,a[i]);}
}
void merge(int a[],int lb, int mid, int ub){
    int i=lb,k=lb,j=mid+1;
    int b[ub+1];
    while(i<=mid&&j<=ub){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
        }else if(a[j]<a[i]){
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            b[k]=a[j];
            j++;k++;
        }
    }else{
        while(i<=mid){
            b[k]=a[i];
            i++;k++;
        }
    }
    for(k=lb;k<=ub;k++){
        a[k]=b[k];
    }
}

void merge_sort(int a[], int lb, int ub){
    int mid=0;
if(lb<ub){
    mid=(lb+ub)/2;
    merge_sort(a,lb,mid);
    merge_sort(a,mid+1,ub);
    merge(a,lb,mid,ub);
}
}
void heapify(int a[],int f,int end){
    int max=f;
    int l=2*f+1;int r=(2*f)+2;
    if(l<end && a[l]>a[max])
    max=l;
    if(r<end && a[r]>a[max])
    max=r;
    if(f!=max){
        int temp=a[max];
        a[max]=a[f];
        a[f]=temp;
        heapify(a,max,end);
    }
}
void build_heap(int a[], int start, int end){
    for(int i=end/2;i>=start;i--){
        heapify(a,i,end);
    }
}
void heap_sort(int a[],int size){
    build_heap(a,0,size);
    for(int i=size;i>=0;i--){
        int temp=a[i];
        a[i]=a[0];
        a[0]=temp;
        heapify(a,0,i-1);
    }
}
int partition(int a[],int lb,int ub){
    int start=lb,end=ub;
    int pivot=a[start];
    while(start<end){
        if(a[start]<=pivot){
            start++;
        }
        if(a[end]>pivot){
            end--;
        } 
        if(start<end){
            int temp=a[start];
            a[start]=a[end];
            a[end]=temp;
        }
    }  
        a[lb]=a[end];
        a[end]=pivot;
        return end;

}
void quick_sort(int a[],int lb,int ub){
    int loc=0;
    if(lb<ub){
        loc=partition(a,lb,ub);
        quick_sort(a,lb,loc-1);
        quick_sort(a,loc+1,ub);
    }
}
void main(){
int size;
printf("Enter the size of the array: ");
scanf("%d",&size);
for(int i=0;i<size;i++){
    printf("Enter the %dth element: ",i+1);
    scanf("%d",&a[i]);
}
printf("Entered elements are:\n");
print(a,size);
// selection_sort(a,size);
// insertion_sort(a,size);
// bubble_sort(a,size);
// merge_sort(a,0,size-1);
heap_sort(a,size-1);
// quick_sort(a,0,size-1);
printf("\nAfter sorting:\n");
print(a,size);
}