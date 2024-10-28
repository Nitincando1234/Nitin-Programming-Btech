#include<iostream>
using namespace std;
namespace one{
class A{
public:
A(){
cout<<"Hi in A A"<<endl;
}
};
class B{
	public:
B(){
cout<<"Hi in B B"<<endl;
}
};
}
namespace Two{                                                                                                            class A{
public:
A(){
cout<<"Hi in A B"<<endl;
}
};
class B{
public:
B(){
cout<<"Hi in B B"<<endl;                                                                                                }
};                                                                                                                      }
int main(){
using one::A;
A a;
using namespace Two;
Two::A b;

return 0;
}
