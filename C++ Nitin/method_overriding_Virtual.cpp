#include <iostream>
using namespace std;
class A{
    public:
     void show(){
        cout<<"IN BASE"<<endl;
    }
};
class B:public A{
    public:
    void show() {
        cout<<"IN DERIVED"<<endl;
    }
};
int main(){
B a;
a.A::show();
return 0;
}