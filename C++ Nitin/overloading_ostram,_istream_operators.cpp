#include<iostream>
using namespace std;
class Employee{
    int id;
    int salary;
    char name[51];
    public:
    friend void operator >> (istream &in,Employee &e){
        cout<<"Enter the ID, Salary, Name:\t";
        fflush(stdin);
        in>>e.id;
        in>>e.salary;
        in>>e.name;}
    friend void operator << (ostream &out,Employee &e){
        cout<<"The ID, Salary, Name:\t";
        out<<e.id<<endl;
        out<<e.salary<<endl;
        out<<e.name<<endl;}
};
int main(){
    Employee e;
    cin>>e;
    cout<<e;
    return 0;
}