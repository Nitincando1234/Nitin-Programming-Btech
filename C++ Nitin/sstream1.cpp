#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main(){
string s;
int i=5;
std::ostringstream ostring_stream_; 
ostring_stream_<<i;
s=ostring_stream_.str()+"This is nitin";
cout<<s<<endl;
std::istringstream istring_stream_(s);
istring_stream_>>i;
cout<<"String converted to string: \n";
cout<<i<<endl;
return 0;
}
