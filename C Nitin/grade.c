#include <stdio.h>
void main (){
    int m1,m2,m3,m4,m5;
    int avg;char grade;
    printf("Enter the marks of 5 subjects:=");
    scanf("%d%d%d%d%d",&m1,&m2,&m3,&m4,&m5);
    avg=(m1+m2+m3+m4+m5)/5;
    printf("\nPercentage:=%d",avg);
    switch (avg/10)
    {
    case 10:
    case 9:    
    case 8:grade='S';
    break;
    case 7:grade='A';
    break;
    case 6:grade='B';
    break;
    case 5:grade='C';
    break;
    case 4:grade='D';
    break;
    default:grade='F';
        break;
    }printf("\nGrade:=%c",grade);
}