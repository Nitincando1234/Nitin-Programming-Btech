#include<stdio.h>
#include<string.h>
char data[100], stuffedData[200], destuffedData[100];
char startEndFrame[] = "01111110";
int i = 0, j = 0, count = 0;
void main(){
    printf("You are a sender...\nEnter the data to send: ");
    scanf("%s", data);
    strcat(stuffedData, startEndFrame);
    j = strlen(startEndFrame);
    for(i = 0; data[i] != '\0'; i++){
        if(data[i] == '1'){
            count++;
            stuffedData[j++] = data[i];
        }
        else{
            count = 0;
            stuffedData[j++] = data[i];
        }
        if(count == 5){
            count = 0;
            stuffedData[j++] = '0';
        }
    }
    strcat(stuffedData, startEndFrame);
    stuffedData[j + strlen(startEndFrame)] = '\0';
    printf("Data is: %s", stuffedData);
    printf("\nYou are now at Reciever side\nGaining Original Data...\n");
    for(i = 0, j = strlen(startEndFrame); j < strlen(stuffedData) - strlen(startEndFrame); j++){
        if(stuffedData[i] == '1'){
            count++;
            destuffedData[i++] = stuffedData[j];
        }
        else{
            count = 0;
            destuffedData[i++] = stuffedData[j];
        }
        if(count == 5){
            count = 0;
            ++j;
        }
    }
    printf("Original Data: %s", destuffedData);
}