#include<stdio.h>
#include<string.h>
#define Flag 'f'
#define Esc 'e'
#define SIZE 1000
void main(){
    char data[SIZE], stuffedData[SIZE];
    int i = 0, j = 0;
    printf("Enter the data: ");
    scanf("%s", data);
    stuffedData[0] = Flag;
    for(j = 1; data[i] != '\0'; i++){
        if((data[i] == Flag) || (data[i] == Esc)){
            stuffedData[j] = Esc;
            j++;
        }
        stuffedData[j] = data[i];
        j++;
    }
    stuffedData[j] = Flag;
    stuffedData[++j] = '\0';
    printf("Stuffed Data: %s", stuffedData);
}