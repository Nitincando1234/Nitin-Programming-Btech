#include<iostream>
using namespace std;

int main(){
	enum suits:char{cars,diamonds,spades, hears};//enumerates to char type
	enum class suits2{myCars,myDiamonds,mySpades,myHears};
	enum carsBrand{bmw=100,mercedes=200,volkswagon=300};

	int c=cars+1;
	//int d=(suits2::myCars)+1;//will cause an error
	char e=diamonds;
	cout<<c<<endl;
	cout<<e<<endl;
	return 0;
}
