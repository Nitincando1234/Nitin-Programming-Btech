#include<iostream>
#include<graphics.h>
#include<conio.h>
int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char *)"");
    line(100,100,500,100);
    getch();
    closegraph();
}