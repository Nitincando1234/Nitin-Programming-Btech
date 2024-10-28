#include <iostream>
using namespace std;
class Point{
    int x;
    public:
    Point(){}
    Point(int a){
        x=a;
    }
    Point(Point &y){
        x=y.x;
    }
    int print(){
        cout<<"The Value of x is: "<<x<<endl;
        return 0;
    }
};
int main(){
    Point p1(23);
    Point p2=p1;
    p1.print();
    p2.print();
    return 0;
}