#include<iostream>
#include<conio.h>
#include<graphics.h>
int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char *)"");
    setbkcolor(WHITE);
        setcolor(BLACK);
        setfillstyle(SOLID_FILL,GREEN);
    for(int x=10;x<=250;x+=10){
        cleardevice();
        bar(50+x,50,150+x,100);
        bar(150+x,75,200+x,100);
        circle(75+x,110,10);
        circle(175+x,110,10);
        delay(100);
    }
    getch();
    closegraph();
    return 0;
}