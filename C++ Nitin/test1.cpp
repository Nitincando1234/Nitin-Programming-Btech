#include<iostream>
using namespace std;
class Point{
    int x,y;
    public:
    void input(int a, int b);
    void output();
};
void Point::input(int a,int b){
    x=a;
    y=b;
}
void Point::output(){
    cout<<x<<endl<<y;
}
int main(){
    int a,b;
    Point obj;
    cout<<"Enter the two numbers";
    cin>>a>>b;
    obj.input(a,b);
    obj.output();
    return 0;
}
