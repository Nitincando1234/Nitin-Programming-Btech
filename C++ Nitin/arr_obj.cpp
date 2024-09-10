#include <iostream>
using namespace std;
class Employee{
    char c[100];
    int id;
    public:
    void getdata(){
        cout<<"Enter Employee Name: ";
        cin>>c;
        cout<<"Enter Employee ID: ";
        cin>>id;
    }
    void putdata(){
        cout<<"Employee Name: "<<c<<" ID: "<<id<<endl;
    }
};
int main(){
    Employee emp[10];
    for(int i=0;i<10;i++){
        cout<<"Enter Details of Employee: "<<i+1<<endl;
        emp[i].getdata();
    }
    cout<<"Entered Details of Employees are as follows: "<<endl;
    for(int i=0;i<10;i++){
        emp[i].putdata();
    }
    return 0;
}
