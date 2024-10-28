#include<bits/stdc++.h>
using namespace std;
int main(){
stack<int> s;
s.push(4);
s.push(5);
s.push(6);
s.pop();
cout<<"The top element of the stack: "<<s.top()<<endl;
if(s.empty())
cout<<"Stack is empty !"<<endl;
else
cout<<"Stack is not empty !"<<endl;
cout<<"The size of the stack: "<<s.size()<<endl;
return 0;
}
