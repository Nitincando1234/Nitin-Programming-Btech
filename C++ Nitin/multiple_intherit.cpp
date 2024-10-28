#include <iostream>
using namespace std;
class data1{
    protected:
    int x;
    public:
    void getdata(){
        cout<<"Enter the value of x: ";cin>>x;
    }
    void printdata(){
        cout<<"The value of x: "<<x<<endl;
    }
};
class data2:public data1{
    protected:
    int y;
    public:
    void getdata(){
        cout<<"Enter the value of y: ";cin>>y;
    }
    void printdata(){
        cout<<"The value of y:"<<y<<endl;
    }
};
class addition:public data2{
    public:
    void sumprint(){
        cout<<"Sum of x and y is: "<<data1::x+y<<endl;
    }
};
int main(){
    addition a;
    a.data1::getdata();
    a.data2::getdata();
    a.data1::printdata();
    a.data2::printdata();
    a.sumprint();
    return 0;
}