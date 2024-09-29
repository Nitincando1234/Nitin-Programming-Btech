#include <stdio.h>
#define SIZE 5
int r=-1,f=-1,a[SIZE];
int enqueue(int num){
    if(r==-1 && f==-1){
        r=0;
        f=0;
        a[r]=num;
    }
    else if((r+1)%SIZE==f){
        printf("Overflow\n");
        return 1;
    }
    else{
        r=(r+1)%SIZE;
        a[r]=num;
    } 
       
    return 0;
}
int dequeue(){
    if(f==-1&& r==-1){
        printf("Underflow\n");
    }
    else if(f==r){
        int temp=a[f];
        r=f=-1;
        return temp;
        
    }
    else{
        int temp=a[f];
        f=(f+1)%SIZE;
        return temp;
    }
    
}
void print(){
    if(f==-1){
        printf("Queue is Empty.\n");
        return; // Added a return statement here to exit if the queue is empty.
    }
    int i = f;
    while(1) {
        printf("%d\t", a[i]);
        if(i == r) break; // Break the loop after printing the last element.
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main(){
    int choice;
    printf("Size of the Queue is: %d\n",SIZE);
    while(1){
        int choice,num;
        printf("Choose the Operation:\n1.Enqueue\n2.Dequeue:");
        scanf("%d",&choice);
        if(choice==1){
            int returned=0;
            int i=0;
            while(1){
                if(returned==1){i=0;break;}
                printf("Enter the %dth value to insert in Queue:",i+1);
                scanf("%d",&num);
                returned=enqueue(num);i++;}
                print();
        }
        else if(choice ==2){
            printf("Dequeuing the %dth value:",f+1);
            printf("Removed %d\n",dequeue());
        }
        else{
            printf("You choosen to print the values:\n");
            print();
        }
    }
return 0 ;
}