#include<iostream>
using namespace std;
template<class T>
class Size{
    T a,b,c;
    public: 
    Size(T l,T m,T n){
        a=l;
        b=m;
        c=n;
    }
    void Display(){
        cout<<"A:"<<a<<endl;
        cout<<"B:"<<b<<endl;
        cout<<"C:"<<c<<endl;
    }
};
int main(){
    Size<int> s(5,6,7);
    Size<double> s1(8.0,9.7,7.4);
    s.Display();
    s1.Display();
    return 0;
}