#include<iostream>
#include<vector>
#include <algorithm> 
using namespace std;
class Person{
    string name;
    int weight,height;
    public:
    Person(string name,int weight,int height){
    this->name=name;
    this->height=height;
    this->weight=weight;
    }
    static bool compare(Person &p1, Person &p2){
        if(p1.weight==p2.weight)
        return p1.height<p2.height;
        else
        return p1.weight<p2.weight;
    }
    void showdata(){
        cout<<name<<" ";
        cout<<weight<<" ";
        cout<<height<<" ";
        cout<<endl;
    }
};
int main(){
    vector<Person> Persons;
    Person p1("Nitin Sharma",75,6);
    Person p2("Alex Rye",70,5);
    Person p3("Paul Verma",90,5);
    Persons.push_back(p1);
    Persons.push_back(p2);
    Persons.push_back(p3);
    sort(Persons.begin(),Persons.end(),Person::compare);
    for(int i=0;i!=Persons.size();i++){
    Persons[i].showdata();
    }
    return 0;
}