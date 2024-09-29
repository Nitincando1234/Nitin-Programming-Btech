#include<iostream>
using namespace std;
class Base{
	protected:
	int base_x;
	public:
	Base(){}
	Base(int a){base_x=a;
	}
	void print(){cout<<"Base Class "<<base_x<<endl;}
};
class Derived:public Base{
	protected:
	int derived_x;
	public:
	Derived(){}
	Derived(int a, int b):Base(a){
	derived_x=b;
	}
	void print(){cout<<"Derived Class "<<base_x<<" "<<derived_x<<endl;}
};
void printer(Base obj){obj.print();}
int main(){
Base b(54);
Derived d(45,65);
printer (b);
b=d;
printer(b);
return 0;
}
