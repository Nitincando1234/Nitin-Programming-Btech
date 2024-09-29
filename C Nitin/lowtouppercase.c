#include <stdio.h>
void main(){
    char ch;
    printf("Enter a character.");
    scanf("%c",&ch);
    if (ch>='A'&&ch<='Z'){
        printf("Character '%c' is in upper case.",ch);
        ch=ch+32;
        printf("In lower case-%c",ch);
    }else if (ch>='a'&&ch<= 'z'){
        printf("Character '%c' is in lower case.",ch);
        ch=ch-32;
        printf("\nIn Upper case-%c",ch);
    }else{
        printf("Please input correct keyword.");
}
}