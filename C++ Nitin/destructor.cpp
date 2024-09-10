#include <iostream>
using namespace std;
class Sample{
    int length;
    char *s;
    public:
    Sample(){}
    Sample(int n){
        s=new char[n+1];
        cout<<"Memory Allocated by constructor: "<<n+1<<" bytes"<<endl;
    }
    ~Sample(){
        delete s;
        cout<<"Memory Releases by destructor"<<endl;
    }
    void display(){
        cout<<"HI"<<endl;
    }
};
int main(){
    Sample s(10);
    s.display();
    return 0;
}
