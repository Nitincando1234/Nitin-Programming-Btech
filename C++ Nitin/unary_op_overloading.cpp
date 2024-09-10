#include <iostream>
using namespace std;
class Increment{
    int value;
    public:
    Increment(){}
    Increment(int a){
        value=a;
    }
    void operator ++ (int){
        value +=5;
    }
    void display(){
        cout<<"Value is: "<<value;
    }
};
int main(){
    Increment i(45);
    i++;
    i.display();
    return 0;
}