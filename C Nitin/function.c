#include<stdio.h>
void namaste(){
    printf("Namaste");
}
void bon(){
    printf("Bonjour");
}
int main(){char n;
printf("Enter i If you Are Indian & f for French:");
scanf("%d",&n);
if(n=='i'||'I'){namaste();}
else if(n=='f'||n=='F'){bon();}
return 0 ;
}