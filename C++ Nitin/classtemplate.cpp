#include<iostream>
using namespace std;
template <class  T>
class num{
    T a;
    public:
    num(T x){a=x;}
    void showdata(){cout<<"Value of a: "<<a;}
};
int main(){
    num<int> n(10);
    n.showdata();

    return 0;
}