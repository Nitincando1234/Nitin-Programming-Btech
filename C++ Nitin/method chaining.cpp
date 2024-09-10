#include<iostream>
using namespace std;
class Size{
int x;
	public:
Size & assignValue(int x){
this->x=x;
return *this;
}
void display(){
cout<<"The value is: "<<x<<endl;
}
};
int main(){
Size s;
s.assignValue(5).display();
return 0;
}
