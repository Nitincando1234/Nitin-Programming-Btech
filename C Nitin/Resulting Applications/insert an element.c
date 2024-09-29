#include <stdio.h>
int main(){
    int a[100],size,num,pos,i;
    printf("Enter the Size:");scanf("%d",&size);
    for( i=0;i<size;i++){
        printf("Enter the %dth value:",i+1);scanf("%d",&a[i]);
    }printf("Enter the value to insert and with position:");scanf("%d%d",&num,&pos);
    if(pos<=0||pos>size+1){ printf("Not valid position.");}
    else{
        for(int i=size;i>=pos;i--){
            a[i]=a[i-1];
        }a[pos-1]=num; printf("new array:\n");for(int i=0;i<size;i++){

            printf("%dth value: %d\n",i+1,a[i]);}
    }
    return 0;
}