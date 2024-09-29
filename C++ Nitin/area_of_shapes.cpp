#include<iostream>
#include <string>
using namespace std;
class shape{
    protected:
    string name;
    double side1,side2;
    public:
    shape(){}
    shape(string n,double a, double b){
        name=n;
        side1=a;side2=b;
    }
};
class triangle:public shape{
    double area;
    public:
    triangle(){}
    triangle(string name,double a,double b):shape(name,a,b){
        cout<<"Triangle is initiated."<<endl;
    }
    void display(){
        cout<<"The Name of the Shape is: "<<shape::name<<endl;
        cout<<"The area is: "<<area;
    }
    void calculateArea(){
        area=(side1*side2)/2;
        display();
    }
};
class rectangle:public shape{
    double area;
    public:
    rectangle(){}
    rectangle(string name,double a,double b):shape(name,a,b){
        cout<<"Rectangle is initiated."<<endl;
    }
    void display(){
        cout<<"The Name of the Shape is: "<<name<<endl;
        cout<<"Area is:"<<area<<endl;
    }
    void calculateArea(){
        area=side1*side1;
        display();
    }
};
class square:public shape{
    double area;
    public:
    square(){}
    square(string name,double a):shape(name,a,a){
        cout<<"Square is initiated."<<endl;
    }
    void display(){
        cout<<"The Name of the Shape is: "<<name<<endl;
        cout<<"Area is:"<<area<<endl;
    }
    void calculateArea(){
        area=side1*side2;
        display();
    }
};
int main(){int choice=0;string name;
    cout<<"Choose the shape to find out the area: 1. Triangle\n2.Rectangle\n3.Square:";cin>>choice;
    switch(choice){
        case 1:{
        cout<<"Enter the name of the shape:";
        cin>>name;
        cout<<"Enter the two side (i.e. Height and Width):";
        double h,b;
        cin>>h>>b;
        triangle t(name,h,b);
        t.calculateArea();
        break;}
        case 2:{
        cout<<"Enter the name of the shape:";
        cin>>name;
        cout<<"Enter the two side (i.e. Lenght and Width):";
        double l,b;
        cin>>l>>b;
        rectangle r(name,l,b);
        r.calculateArea();
        break;}
        case 3:{
        cout<<"Enter the name of the shape:";
        cin>>name;
        cout<<"Enter the two side (i.e. Lenght of One Side):";
        double l,b;
        cin>>l;
        square s(name,l);
        s.calculateArea();
        break;}
        default:{
        cout<<"Invalid Choice."<<endl;}
    }
    return 0;}