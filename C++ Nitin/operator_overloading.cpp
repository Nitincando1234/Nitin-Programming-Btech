#include<iostream>
#include<cstring>
using namespace std;
class String{
    char *string=new char[50];
    public:
    void getstring(){
        cout<<"Enter the string: ";
        fflush(stdin);
        cin>>string;
    }
    String operator + (String &s){
        String temp;
        temp.string=strcat(string,s.string);
        return temp;
    }
    void print (){
        cout<<"String is: "<<string;
    }
};
int main(){
    String s1,s2;
    s1.getstring();
    s2.getstring();
    String s3;
    s3=s1+s2;
    s3.print();
    return 0;
}