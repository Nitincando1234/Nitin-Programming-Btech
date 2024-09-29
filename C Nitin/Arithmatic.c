#include <stdio.h>
void main (){
    int n1,n2,ch;
    printf("Enter choice");
    printf("\nAdd:  1\nSub:  2\nMul:  3\nDiv:  4\nRem:  5\n");
    scanf("%d",&ch);
    printf("Enter two numbers:");
    scanf("%d%d",&n1,&n2);
    switch (ch)
    {
    case 1:
        printf("Addition of these no. is: %d",n1+n2);
        break;
          case 2:
        printf("Substraction of these no. is: %d",n1-n2);
       break;
          case 3:
        printf("Multiplication of these no. is: %d",n1*n2);
        break;
          case 4:
        printf("Division of these no. is: %d",n1/n2);
        break;
          case 5:
        printf("Remainder of these no. is: %d",n1%n2);
        break;
    default:
        break;
    }
}