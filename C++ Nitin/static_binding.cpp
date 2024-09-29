#include <iostream>
using namespace std;
class Base{
    public:
    //Add
    //virtual
    //to make virtual function
    //plus Dynamic Binding
     void show(){
        cout<<"In BASE"<<endl;
    }
};
class Derived:public Base{
    public:
    void show(){
        cout<<"In DEERIVED"<<endl;
    }
};
int main(){
    Base *obj;
    Derived a;
    obj=&a;
    obj->show();
    return 0;
}