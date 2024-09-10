#include<iostream>
#include<string>
using namespace std;
class Person{
    protected:
    int age;
    string name;
    public:
    void getAgeName(int a, string n){
        name=n;
        age=a;
    }
};
class Student:virtual public Person{
    protected:
    int classl=0;
    public:
    void getClass(int x){
    classl=x;
    }
};
class Teacher:virtual public Person{
    protected:
    string post="";
    public:
    void getPost(string p){
    post=p;
    }
};
class TA:public Student,public Teacher{
    int salary;
    public:
    void getSalary(int s){
    salary=s;
    }
    void printDetails(){
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
    if(classl==0)cout<<"No class For Teacher"<<endl;
    cout<<"Class: "<<classl<<endl;
    if(post=="")cout<<"No post For a Student"<<endl;
    cout<<"Post: "<<post<<endl;
    cout<<"Salary: "<<salary;
    }
};
int main(){
    TA a;
    a.getPost("newCommer");
    a.getAgeName(18,"Nitin Sharma");
    a.getSalary(10000000);
    a.printDetails();
    return 0;
}