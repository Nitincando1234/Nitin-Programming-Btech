#include<stdio.h>
#include<string.h>
#define N strlen(gen_poly)
char gen_poly[28], data[50], checker[50];
int i, j, data_len;
void XOR(){
    for(j = 1; j < N; j++)
        checker[j] = ((checker[j] == gen_poly[j]) ? '0' : '1');
}
void crc(){
    for(i = 0; i < N; i++) checker[i] = data[i];
    do{ 
        if(checker[0] == '1')XOR();
        for(j = 0; j < N - 1; j++) 
            checker[j] = checker[j + 1];
        checker[j] = data[i++];
    }while(i <= data_len + N - 1);
}
void reciever(){
    printf("\nEnter the recived data:");
    scanf("%s", data);
    crc();
    for(i = 0; ((i < N -1) && (checker[i] != '1')); i++){}
    if(i < N - 1) printf("\nError Detected !");
    else printf("\nNo Error !");
}
void main(){
    printf("Enter the data: ");
    scanf("%s", data);
    data_len = strlen(data);
    printf("Enter the generative polynomial: ");
    scanf("%s", gen_poly);
    for(i = data_len; i < data_len + N - 1; i++)
        data[i] = '0';
    printf("Data after padding: %s", data);
    crc();
    printf("\nCRC is: %s", checker);
    for(i = data_len; i < data_len + N - 1; i++)
        data[i] = checker[i - data_len];
    printf("\nFinal data to be sent: %s", data);
    reciever();
}