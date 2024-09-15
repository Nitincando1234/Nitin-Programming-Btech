#include <stdio.h>
int main(){
    int a[100],size,pos,i;
    printf("Enter the Size:");scanf("%d",&size);
    for( i=0;i<size;i++){
        printf("Enter the %dth value:",i+1);scanf("%d",&a[i]);
    }printf("Enter the position of the value to delete:");scanf("%d",&pos);
    if(pos<0||pos>size-1){printf("Entered wrong position.");}
    else{for(int i=pos-1;i<size;i++){
    a[i]=a[i+1];
        }
    }size--;
    for(int i=0;i<size;i++){
        printf("%dth value is: %d\n",i+1,a[i]);
    }
    return 0;
}