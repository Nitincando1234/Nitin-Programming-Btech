#include <iostream>
using namespace std;
class ABC;
class XYZ{
    int x;
    public:
    XYZ(){}
    XYZ(int b){
        x=b;
    }
    void show (){
        cout<<"Value of Y: "<<x<<endl;
    }
    friend void swap (ABC &,XYZ &);
};
class ABC{
    int a;
    public:
    ABC(){}
    ABC(int z){
        a=z;
    }
    void show(){
        cout<<"Value of X: "<<a<<endl;
    }
    friend void swap (ABC &,XYZ &);
};
void swap(ABC &m,XYZ &n){
    int t=m.a;
    m.a=n.x;
    n.x=t;
}

int main(){
    ABC a(5);
    XYZ b(4);
    swap(a,b);
    a.show();
    b.show();
    return 0;
}
