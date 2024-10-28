#include <iostream>
using namespace std;
class Point{
    int a,b;
    public:
    void input(int& , int& );
    void output(int , int);
};
void Point::input(int &a,int &b){
    cout<<"Enter x and y: "<<endl;
    cin>>a>>b;
}
void Point::output(int a,int b){
    cout<<"X: "<<a<<" Y: "<<b<<endl;
}
int main(){
    Point p;
    int a,b;
    p.input(a,b);
    p.output(a,b);
    return 0;
}
