#include <iostream>
#include <cstring>
using namespace std;
    class Strings {
        char *name;
        int length;
        public:
        Strings(){
            length=0;
            name=new char[length+1];
        }
        Strings(const char *s ){
            name=new char[strlen(s)+1];
            strcpy(name,s);
        }
        void display(){
            cout<<name<<endl;
        }
    };
int main(){
    Strings s("Ajmer");
    s.display();
    return 0;
}