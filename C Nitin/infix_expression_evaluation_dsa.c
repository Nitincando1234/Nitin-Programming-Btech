#include<stdio.h>
#define MAX 20
int isOperand(char c){
    if(c>='0'&&c<='9')return 1;
    else
    return 0;
}
int value(char c){
    return (c-'0');
}
int evaluate(char expr[MAX]){
    int res=value(expr[0]);
    for(int i=1;expr[i];i+=2){
    int opr=expr[i],opd=expr[i+1];
    if(!isOperand(opd))return -1;
    if(opr=='+')res+=value(opd);
    else if(opr=='-')res-=value(opd);
    else if(opr=='*')res*=value(opd);
    else if(opr=='/')res/=value(opd);
    else return -1;
    }
    return res;
}
void main(){
    char expr[MAX]="2+5/3*7-1";
    int result=evaluate(expr);
    if(result==-1)printf("The operator is either -1 or operand is not in correct position !\n");
    printf("Result Of Expression: %d",result);
}