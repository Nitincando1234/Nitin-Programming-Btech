#include<stdio.h>
void main(){
    // work for 11 bit data 
    char data[11], datarec[11], parity_bit, c1, c2, c4, c8;
    int test = 0;
    printf("At Sender Side\n");
    printf("Enter the 11-bit data: ");
    for(int i = 0; i <= 10; i++){
        scanf("%d", &data[i]);
    }
    printf("At sender side data is:\n");
    for(int i = 0; i <= 10; i++){
        printf("%d", data[i]);
    }
    printf("\n");
    data[0] = data[2] ^ data[4] ^ data[6] ^ data[8] ^ data[10];
    data[1] = data[2] ^ data[5] ^ data[6] ^ data[9] ^ data[10];
    data[3] = data[4] ^ data[5] ^ data[6];
    data[7] = data[8] ^ data[9] ^ data[10];

    printf("\nAt Reciever Side\n");
    printf("Enter the recieved 11-bit data: ");
    for(int i = 0; i <= 10; i++){
        scanf("%d", &datarec[i]);
    }
    printf("At sender side data is:\n");
    for(int i = 0; i <= 10; i++){
        printf("%d", data[i]);
    }
    printf("\n");
    for(int i = 0; i<= 10; i++){
            if(datarec[i] == data[i]) test = 0;
            else test = 1;
    }
    c1 = datarec[0] ^ datarec[2] ^ datarec[4] ^ datarec[6] ^ datarec[8] ^ datarec[10];
    c2 = datarec[1] ^ datarec[2] ^ datarec[5] ^ datarec[6] ^ datarec[9] ^ datarec[10];
    c4 = datarec[3] ^ datarec[4] ^ datarec[5] ^ datarec[6];
    c8 = datarec[7] ^ datarec[8] ^ datarec[9] ^ datarec[10];
    parity_bit = c1 + (c2 * 2) + (c4 * 4) + (c8 * 8);
    // printf("%d", parity_bit);
    if(test == 0)
    printf("There is no problem in the recieved data !!!");
    else{
        datarec[parity_bit + 1] = datarec[parity_bit + 1] ^ 1;
        printf("Problem at position: %d\n", parity_bit + 1);
        printf("Fixed the problem !!!");

        printf("After Correction ");
    }
    printf("At reciever side data is:\n");
    for(int i = 0; i <= 10; i++){
        printf("%d", datarec[i]);
    }
    printf("\n");
}