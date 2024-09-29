#include<iostream>
#include<graphics.h>
#include<conio.h>
int main(){
    int gm=DETECT,gd;
    initgraph(&gm,&gd,(char *)"");
    setcolor(YELLOW);
    bar(50,50,100,100);
    bar3d(200,200,300,300,20,1);
    getch();
    closegraph();
    return 0;
}