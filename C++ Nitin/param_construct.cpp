#include <iostream>
using namespace std;
class Point{
    int x,y;
    public:
    Point(){}
    Point(int a,int b){
        x=a;y=b;
    }
    void putdata(){
        cout<<"X: "<<x<<" Y: "<<y<<endl;
    }
};
int main(){
    Point p1(32,54),p2(54,78);
    p1.putdata();
    p2.putdata();
    return 0;
}