#include "version.h"
#include<iostream>
using namespace std;
string app_name="Port Scanner";
void usage(){
    cout<<app_name<<endl;
}
int main(){
    printf("Value of version is: %d",version);
    usage();
    return 0;
}