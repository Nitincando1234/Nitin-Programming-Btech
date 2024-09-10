#include <iostream>
using namespace std;
class ABC;
class XYZ;
void swap(ABC &a,XYZ&b){
    int temp=a.a;
    a.a=b.x;
    b.x=temp;
}
int main(){
    ABC m(10);
    XYZ n(20);
    swap(m,n);
    m.show();
    n.show();
    return 0;
}
class ABC{
    int a;
    public:
    ABC(){}
    ABC(int x){
        a=x;
    }
    friend void swap(ABC &,XYZ &);
    friend XYZ;
    void show(){
        cout <<"Value is : "<<a<<endl;
    }
};

class XYZ{
    int x;
    public:
    XYZ(){}
    XYZ(int a){
        x=a;
    }
    friend void swap(ABC &,XYZ&);
    friend void ABC::show(){}
};

