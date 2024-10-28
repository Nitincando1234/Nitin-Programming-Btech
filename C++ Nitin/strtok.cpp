#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char str[100][50];
    char *string=new char[1000];
    cout<<"Enter the string: ";
    fgets(string,1000,stdin);
    char *token=strtok(string," ");
    int i=0,tokencount=0;
    while(token!=NULL){
        strcpy(str[i],token);
        token=strtok(NULL ," ");
        i++;tokencount++;
    }
    for(int i=tokencount-1;i>=0;i--){
        cout<<"\""<<str[i]<<"\""<<endl;
    }

    return 0;
}