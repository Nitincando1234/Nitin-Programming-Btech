#include <iostream>
using namespace std;
class Base{};
class Derived : public Base{};
int main(){
    Derived d;
    try {
        throw d;
    }
    catch(Derived){
        cout<<"Caught Derived Exception."<<endl;
    }
    catch(Base){
        cout<<"Caught Base Exception."<<endl;
    }
    return 0;
}