#include<graphics.h>
#include<conio.h>
#include<iostream>
#include<ctime>
int main(){
    srand(time(0));
    int gm,gd=DETECT;
    initgraph(&gd,&gm,(char *)"");
    setcolor(1);
    circle(getmaxx()/2,getmaxy()/2,20);
    setcolor(2);
    circle(getmaxx()/2,getmaxy()/2,50);
    setcolor(3);
    circle(getmaxx()/2,getmaxy()/2,80);
    setcolor(4);
    circle(getmaxx()/2,getmaxy()/2,110);
    setcolor(5);
    circle(getmaxx()/2,getmaxy()/2,140);
    getch();
    system("cls");
    for(int rad=20;rad<=300;rad+=20){
    setcolor(rand()%15);
    circle(getmaxx()/2,getmaxy()/2,rad);
    }
    getch();
    closegraph();
    return 0;
}