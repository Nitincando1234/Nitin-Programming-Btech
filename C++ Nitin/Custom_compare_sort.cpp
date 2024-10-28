#include<bits/stdc++.h>
using namespace std;
class Person{
public:
string name;
int age;
};

bool compare(Person &p1,Person &p2){
if(p1.age==p2.age)
return p1.name>p2.name;

else
return p1.age>p2.age;}

int main(){
vector<Person> p;
p.push_back({"Nitin",19});
p.push_back({"Axxxx",20});
p.push_back({"Bxxxx",21});
sort(p.begin(),p.end(),compare);
for(vector<Person>::iterator it=p.begin();it!=p.end();it++){
cout<<"Name: "<<it->name<<"\nAge: "<<it->age<<endl;
}
return 0;
}
