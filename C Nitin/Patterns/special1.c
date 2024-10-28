#include<stdio.h>
void main(){
    int size,min;
    printf("Enter the size of the pattern: ");
    scanf("%d",&size);
    for(int i=1;i<size*2;i++){
        for(int j=1;j<size*2;j++){
            int a=i;
            int b=j;
            if(a>size)a=2*size-a;
            if(b>size)b=2*size-b;
            if(a<=b)min=a;
            else min=b;
            printf("%d",size+1-min);
        }printf("\n");
    }
}