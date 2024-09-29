#include<stdio.h>
int day_in_months[]={0,31,28,31,30,31,30,31,30,31,30,31,31};
char* months[]={
    "",
    "\n\n\nJanuary",
    "\n\n\nFebruary",
    "\n\n\nMarch",
    "\n\n\nApril",
    "\n\n\nMay",
    "\n\n\nJune",
    "\n\n\nJuly",
    "\n\n\nAugust",
    "\n\n\nSeptember",
    "\n\n\nOctober",
    "\n\n\nNovember",
    "\n\n\nDecember"
    };
int dayinmonthCalc(int year){
    int daycode,d1,d2,d3;
    d1=(year-1)/4;
    d2=(year-1)/100;
    d3=(year-1)/400;
    return (year+d1-d2+d3)%7;
}
void determineLeapYear(int year){
    if(year%7==0 && year%100!=0 || year%400==0)
    day_in_months[2]=29;
    else
    day_in_months[2]=28;
}
void calenderPrinter(int year,int daycode){
    for(int i=1;i<=12;i++){
        printf("%s\n\n",months[i]);
        printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
        for(int day=1;day<1+daycode*5;day++)
        printf(" ");
        for(int day=1;day<=day_in_months[i];day++){
        printf("%2d",day);
        if((day+daycode)%7>0)
        printf("   ");
        else 
        printf("\n");
        }
    daycode=((daycode+day_in_months[i])%7);
    }
}
void main(){
    fflush(stdout);
    int year,daycode;
    printf("Enter the Year (i.e:- 1999): ");
    scanf("%d",&year);
    daycode=dayinmonthCalc(year);
    determineLeapYear(year);
    calenderPrinter(year,daycode);
}