/*WAP to take marks of five subjects for student as input and 
calculate grades according to following rules:- 
Division Range Grade 
>=85 ‘S’ 
>=75 - <=84 ‘A’ 
>=65 - <=74 ‘B’ 
>=55 - <=64 ‘C’ 
>=50 - <=54 ‘D’ 
<50 ‘F’ */ 
#include<stdio.h>
#include<math.h>
void main(){
  int m1,m2,m3,m4,m5;
  float avg;char grade;
  printf("Enter marks:-\n");
  printf("marks 1:\n");
  scanf("%d",&m1);
  printf("marks 2:\n");
   scanf("%d",&m2);
  printf("marks 3:\n");
   scanf("%d",&m3);
  printf("marks 4:\n");
   scanf("%d",&m4);
  printf("marks 5:\n");
 scanf("%d",&m5);
 avg=(m1+m2+m3+m4+m5)/5;
 printf("Percentage:-%f",avg);
 if(avg>=85){grade='S';
 }else if(avg>=75&&avg<85){
grade='A';
 }else if(avg>=65&&avg<75){
grade='B';
 }else if(avg>=55&&avg<65){
grade='C';
 }else if(avg>=50&&avg<55){
grade='D';
 }else {
grade='F';
 }
 printf("\nGrade:-%c",grade);
}