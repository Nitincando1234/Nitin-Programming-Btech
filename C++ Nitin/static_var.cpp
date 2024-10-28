#include <iostream>
using namespace std;
class item{
    static int count;
    int product_id;
    public:
    item(){}
    item(int a){
        product_id=a;
        count++;
    }
    void getid(){
        cout<<"Product ID is: "<<product_id<<endl;
    }
    void getcount(){
        cout<<"Count is: "<<count;
    }
};
int item::count=0;
int main(){
    item i1(9786);
    item i2(9787);
    item i3(9788);
    i1.getid();
    i2.getid();
    i3.getid();
    i3.getcount();
    return 0;
}