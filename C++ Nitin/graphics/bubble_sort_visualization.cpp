//run using ./output.exe file
#include<iostream>
#include<ctime>
#include<graphics.h>
#include<cstring>
#include<sstream>
#define Y_offset 25
#define size 200
#define gap 4
using namespace std;
void swap(int i,int j,int x,int y){
    setcolor(GREEN);
    line(i,size,i,size-x);
    setcolor(BLACK);
    line(i,size,i,size-x);
    setcolor(WHITE);
    line(i,size,i,size-y);

    setcolor(GREEN);
    line(j,size,j,size-y);
    setcolor(BLACK);
    line(j,size,j,size-y);
    setcolor(WHITE);
    line(j,size,j,size-x);
}
int main(){
    srand(time(0));
    int a[size];
    for(int i=0;i<size;i++){
        a[i]=rand()%201;
    }
    cout<<"Elements are :\n";
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    int gd=DETECT,gm;
    initwindow(1024,512,"My Sorting Visualization Program !");
    for(int i=1;i<size;i+=gap){
        line(i,size,i,size-a[i/gap]);
    }
    settextstyle(1,0,1);
    outtextxy((getmaxx()/2)-350,getmaxy()/2,"^^^^^^^^^^ Ascending order sort for 200 elements ^^^^^^^^^^");
    for(int i=1;i<size;i++){
        for(int j=0;j<size-i;j++){
            if(a[j+1]<a[j]){
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            swap(gap*j+1,gap*(j+1)+1,a[j+1],a[j]);
            }
        }
            //delay(20);
    }
    delay(2000);
    cleardevice();
    outtextxy(0,0,"Elements after the sorting:");
    int y=25;
    int x=0;
    for(int i=0;i<size;i++){
        const char *str=(const char*)malloc(sizeof(char)*50);
        stringstream ss;
        ss<<a[i];
        string element=ss.str();
        str=element.c_str();
        if(i%15==0){
        x=0;
        y+=Y_offset;
        }
        outtextxy(x,y,const_cast<char *>(str));
        free(const_cast<char *>(str));
        x+=50;
    }
    getch();
    closegraph();
    return 0;
}