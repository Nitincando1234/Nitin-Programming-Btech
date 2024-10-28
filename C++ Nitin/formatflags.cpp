#include<iostream>
using namespace std;
int main(){
auto format=(ios::showpos|ios::showbase|ios::showpoint);
cout.setf(format);
cout.precision(5);
cout<<hex<<40<<endl;
cout<<-1.50f<<endl;
return 0;
}
