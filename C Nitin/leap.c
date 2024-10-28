#include <stdio.h>
void main (){
    /*Write a menu driven program which has following option:- 
 Odd or Even 
 Greatest no. b/w any two no. 
 Leap Year */
int ch,a,b,c,d;
printf("Enter your choice");
printf("\n1.Odd or Even\n2.Greatest no. b/w any two no.\n3. Leap Year */\n");
scanf("%d",&ch);
switch (ch)
{
case 1:
printf("Enter any no:");
scanf("%d{",&a);
if(a%2==0){
    printf("No. is even.");
}else {
    printf("No is odd.");
}
    break;
case 2:
printf("Enter any two no:");
scanf("%d%d",&a,&b);
c=(a>b)?a:b;
printf("Maximum:%d",c);
break;
case 3:
printf("Enter the year:");
scanf("%d",&a);
if (a%4==0){
printf("Year is a Leap year.");
}else
{printf("Year is a non Leap year.");}
break;
default:
    break;
}

}