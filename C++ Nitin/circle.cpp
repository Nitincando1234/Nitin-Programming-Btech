#include<iostream>
#define PI 3.14
using namespace std;
class Circle{
    double area,circumference,radius;
    public:
    Circle(){}
    Circle(double b){
        radius=b;
    }
    void calculateArea(){
        area=PI*(radius*radius);
        circumference=2*PI*radius;
        cout<<"Area is: "<<area<<endl<<"Circumference is: "<<circumference<<endl;
    }
};
int main(){
    double radius;
    cout<<"Enter the Radius of the Circle: ";
    cin>>radius;
    Circle c(radius);
    c.calculateArea();
    return 0;
}