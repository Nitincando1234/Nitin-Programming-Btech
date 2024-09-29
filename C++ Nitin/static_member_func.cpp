#include <iostream>
using namespace std;
class test{
    int x;
    static int y;
    public:
    void set_x(int a){
        x=a;
        y++;
    }
    void show_x(){
        cout<<"X: "<<x<<endl;
    }
    static void show_y(){
        cout<<"Y: "<<y<<endl;
    }
};
int test::y=0;
int main(){
    test t1;
    test t2;
    t1.set_x(10);
    t2.set_x(20);
    t1.show_x();
    t2.show_x();
    t2.show_y();
    return 0;
}