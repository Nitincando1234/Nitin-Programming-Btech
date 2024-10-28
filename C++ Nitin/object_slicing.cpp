#include<iostream>
using namespace std;
class Base{
    int base_var;
    public:
    virtual void display(int a){
        cout<<"The value is : "<<a<<endl;
    }
};
class Derived:public Base{
    int derived_var;
    public:
    void display(int a){
        cout<<"The value is : "<<a<<endl;
    }
    void show(int a){
        cout<<"Also showing the value : "<<a<<endl;
    }
};
int main(){
    Base *b;
    Derived d;
    b=&d;
    b->display(5);
    d.show(34);
    Base b1;
    b1=d;
    b1.display(54);
    return 0;
}