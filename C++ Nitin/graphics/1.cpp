#include<graphics.h>
#include<stdio.h>
#include<conio.h>
int main(){
int fd=DETECT,gm;
char graphicDriver[]="C:\\MinGW\\lib\\libbgi.a";
initgraph(&fd,&gm,graphicDriver);
outtext("Hello World !");
outtextxy(getmaxx()/2,getmaxy()/2,"Hello World Again !");
getch();
closegraph();
}
