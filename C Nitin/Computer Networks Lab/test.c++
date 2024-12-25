#include<stdio.h>
int main(){
    char data[11], datarec[11];
    int parity_bit, c1, c2, c4, c8, test = 0;
    printf("Enter the data at sender side: ");
    for(int i = 0; i < 11; i++){
        fflush(stdin);
        scanf("%d", &data[i]);
    }

    data[0] = data[4] ^ data[6] ^ data[8] ^ data[10];
    data[1] = data[2] ^ data[5] ^ data[6] ^ data[9] ^ data[10];
    data[3] = data[4] ^ data[5] ^ data[6];
    data[7] = data[8] ^ data[9] ^ data[10];
    printf("\nHamming Code Encoded Data:\n");
    for(int i = 0; i < 11; i++){
        printf("%d", data[i]);
    }

    printf("\nEnter the data at reciever side: ");
    for(int i = 0; i < 11; i++){
        scanf("%d", &datarec[i]);
    }
    c1 = datarec[2] ^ datarec[4] ^ datarec[6] ^ datarec[8] ^ datarec[10];
    c2 = datarec[1] ^ datarec[2] ^ datarec[5] ^ datarec[6] ^ datarec[9] ^ datarec[10];
    c4 = datarec[3] ^ datarec[4] ^ datarec[5] ^ datarec[6];
    c8 = datarec[7] ^ datarec[8] ^ datarec[9] ^ datarec[10];
    
    for(int i = 0; i < 11; i++){
        if(data[i] != datarec[i]){
            test = 1;
            break;
        }
    }
    if(test == 1){
        parity_bit = c1 + (c2 * 2) + (c4 * 4) + (c8 * 8);
        printf("Problem at %d", parity_bit);
        if(datarec[parity_bit - 1] == 0)
        datarec[parity_bit - 1] = 1;
        else
        datarec[parity_bit - 1] = 0;
        printf("\nAfter Fixing at reciever side: \n");
        for(int i = 0; i < 11; i++){
        printf("%d", datarec[i]);
    }   
    }
    else{
        printf("No Problem !");
    }
}