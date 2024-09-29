#include<graphics.h>
#include<iostream>
#include<conio.h>
int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char *)"");
    for(int rad=20;rad<=200;rad++){
        setcolor(rad/10);
        arc(getmaxx()/2,getmaxy()/2,0,180,rad);
    }
    getch();
    closegraph();
    return 0;
}