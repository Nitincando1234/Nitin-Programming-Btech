#include<iostream>
#include<string>
using namespace std;
class Shape{
    protected:
    float side1,side2;string name;
    public:
    Shape(){}
    Shape(int a,int b,string namel){side1=a;side2=b;name=namel;}
};
class Triangle:public Shape{
    float area;
    public:
    Triangle(){}
    Triangle(float a, float b,string name):Shape(a,b,name){}
    void areaCalc(){
        area=(Shape::side1*Shape::side2)/2;
    }
    void display(){
        cout<<"Name of Shape Square: "<<Shape::name<<endl;
        cout<<"Area of Triangle: "<<area<<endl;
    }
};

class Square:public Shape{
    float area;
    public:
    Square(){}
    Square(float a, float b,string name):Shape(a,b=a,name){}
    void areaCalc(){
        area=(Shape::side1*Shape::side2);
    }
    void display(){
        cout<<"Name of Shape Square: "<<Shape::name<<endl;
        cout<<"Area of Square: "<<area<<endl;
    }
};
int main(){
    float a,b;
    cout<<"Enter the two sides : ";cin>>a>>b;
    Square t(a,b,"Nitin");
    t.areaCalc();
    t.display();
    return 0;
}