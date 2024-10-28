#include<iostream>
#include<graphics.h>
#include<conio.h>
int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char *)"");
    int y=0;
    for(int font=0;font<11;font++,y+=25){
        settextstyle(font,0,0);
        outtextxy(0,y,"Hello World !");
    }   
    getch();
    closegraph();
    return 0;
}