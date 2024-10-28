#include<graphics.h>
#include<conio.h>
#include<iostream>
int main(){
    int gd,gm=DETECT;
    initgraph(&gm,&gd,(char *)"");
    rectangle(150,150,250,200);
    circle((getmaxx()/2),(getmaxy()/2)+40,50);
    rectangle(getmaxx()-150,150,getmaxx()-250,200);
    arc(getmaxx()/2,getmaxy()/2,0,360,220);
    getch();
    closegraph();
    return 0;
}