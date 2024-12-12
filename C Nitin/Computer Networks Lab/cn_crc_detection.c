#include<stdio.h>
#include<string.h>
#define gen_poly_length strlen(gen_poly)
char gen_poly[50], data[100], checker[100];
int i, j;
void XOR(){
    for(j = 1; j < gen_poly_length; j++)
        checker[j] = ((checker[j] == gen_poly[j]) ? '0' : '1');
}
void crc(){
    for(i = 0; i < gen_poly_length; i++){
        checker[i] = data[i];
    }
    do{
        if(checker[0] == '1') XOR();
        for(j = 0; j < gen_poly_length - 1; j++)
        checker[j] = checker[j + 1];
        checker[j] = data[i++];
    }while(i < strlen(data) + gen_poly_length);
}
void reciever(){
    printf("\nEnter the recived data: ");
    scanf("%s", data);
    printf("The data recieved is: %s", data);
    crc();
    for(i = 0; (i < gen_poly_length - 1) && (checker[i] != '1'); i++)
    if(i < gen_poly_length - 1) printf("\nError Detected !");
    else printf("\nNo Error Detected !");
}
void main(){
    printf("\nEnter the data: ");
    scanf("%s", data);
    printf("\nEnter the Generator Polynomial: ");
    scanf("%s", gen_poly);
    printf("Generating Polynomial is: %s", gen_poly);
    for(i = strlen(data); i < strlen(data) + gen_poly_length - 1; i++){
        data[i] = '0';
    }
    printf("\nData after padding added: %s", data);
    crc();
    printf("\nCRC is: %s", checker);
    for(i = strlen(data); i < strlen(data) + gen_poly_length - 1; i++){
        data[i] = checker[i - strlen(data)];
        }
    printf("\nData after adding the CRC: %s", data);
    reciever();
}