#include<stdio.h>
#include<math.h>
void main (){
    // Day to YY-MM--DD Format.
    int days, week, year;
    printf("Please Input the no. of Days: ");
    scanf("%d",&days);
    year=days/365;
    week=days%365/7;
    days=days-((year*365)+(week*7));
    printf("%d-%d-%d",year,week,days);
}