#include <iostream>
using namespace std;
class Operator{
    float x,y;
    public:
    Operator(float a,float b){
        x=a;y=b;
    }
    Operator(){}
    Operator operator +(Operator c){
        Operator temp;
        temp.x=x+c.x;
        temp.y=y+c.y;
        return temp;
    }
    void display(){
        cout<<"Real "<<x<<"+ imag "<<y<<endl;
    }
};
int main(){
    Operator o1(53.2f,45.63f),o2(54.54f,346.45f);
    Operator o3=o1+o2;
    o3.display();
    return 0;
}