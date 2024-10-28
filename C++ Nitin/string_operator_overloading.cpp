#include<iostream>
#include<string>
using namespace std;
class String{
    string str;
    public:String(){cout<<"String can't be Empty!"<<endl;}
    String(string newstr){
        str=newstr;
    }
    String operator + (String &c){
        String temp;
        temp.str=str;
        temp.str.append(" ");
        temp.str.append(c.str);
        return temp;
    }
    void display(){
        cout<<"New Appended string is: "<<str<<'\n';
    }
};
int main(){
    string one,two;
    cout<<"Enter the first string: ";getline(cin,one);
    cout<<"Enter the second string: ";getline(cin,two);
    String s3(""),s1(one),s2(two);
    s3=s1+s2;
    s3.display();
    return 0;
}