#include <iostream>
using namespace std;
class A{//abstract class
    public:
    virtual void display(int)=0;
};
class B:public A{
    public:
    void display(int a){
        cout<<"Value is : "<<a<<endl;
    }
};
int main(){
    B a;
    a.display(35265);
    return 0;
}