#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<cstdlib>
int main(){
    int gm=DETECT,gd;
    char *str;
    str=(char*)malloc(sizeof(char)*50);
    initgraph(&gm,&gd,(char*)"");
    sprintf(str,"Current Working/Drawing color:- %d",getcolor());
    outtextxy(0,0,str);
    free(str);
    str=(char*)malloc(sizeof(char)*50);
    sprintf(str,"Current Working Cursor Position:- X=%d Y=%d",getx(),gety());
    outtextxy(0,20,str);
    free(str);
    str=(char*)malloc(sizeof(char)*50);
    sprintf(str,"Colors available in current graphics mode:- %d",getmaxcolor());
    outtextxy(0,40,str);
    setbkcolor(GREEN);
    setfillstyle(SOLID_FILL,RED);
    ellipse(getmaxx()/2+100,getmaxy()/2,0,360,50,100);
    fillellipse(getmaxx()/2-100,getmaxy()/2,10,20);
    getch();
    closegraph();
    return 0;
}