#include <iostream>
using namespace std;
class data{
    protected:
    int x,y;
    public:
    void getdata(int a, int b){
        x=a;y=b;
    }
    void putdata(){
        cout<<"X: "<<x<<" Y: "<<y<<endl;
    }
};
class maximum:public data{
public:
void max(){
if(x>y){
    cout<<"Maximum is: "<<x<<endl;
}
else
cout<<"Maximum is: "<<y<<endl;
}};
int main(){
    maximum d;
    d.getdata(10,20);
    d.putdata();
    d.max();
    return 0;
}