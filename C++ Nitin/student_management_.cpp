#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<unistd.h>
#include<stdio.h>
using namespace std;
class temp{
string name,fname,roll;fstream file;
public:
string filename="studentdetails.txt";
void addstudent();
void viewstudents();
void searchstudents();
}obj;
int main(){
    cout<<"-------------------------------"<<endl;
    cout<<"1. Add Student :: "<<endl;
    cout<<"2. View Students :: "<<endl;
    cout<<"3. Search Student :: "<<endl;
    cout<<"4 or o/w. Exit :: "<<endl;
    cout<<"-------------------------------"<<endl;
    int choice;
    cin>>choice;
    switch((int)choice){
        case 1:{
            cin.ignore();
            obj.addstudent();break;
        }
        
        case 2:{
            cin.ignore();
            obj.viewstudents();break;
        }
        
        case 3:{
            cin.ignore();
            obj.searchstudents();break;
        }
        case 4:{
            cin.ignore();
            break;
        }
        default:{
            cout<<"Exited by Invalid Choice !"<<endl;
            break;
        }
    }
    return 0;
}
void temp::addstudent(){
    cout<<"Student Name :: ";
    getline(cin,name);
    cout<<"Student Roll no. :: ";
    cin>>roll;
    cin.ignore();
    cout<<"Student's Father Name :: ";
    getline(cin,fname);
    file.open(temp::filename,ios::out|ios::app);
    file<<name<<"*"<<fname<<"*"<<roll<<"\n";
    file.close();
    cout<<"Added the details successfully \1"<<endl;
}
void temp::viewstudents(){
    file.open(filename,ios::in);
    if(!file.is_open()){
        file.close();
        cout<<"File is Not Created Even !\nCreating..."<<endl;
        Sleep(2000);
        cout<<"File Created Successfully"<<endl;
        temp::addstudent();
    }
    while(getline(file, name, '*') && getline(file, fname, '*') && getline(file, roll, '\n')&&!file.eof()){
    cout<<"Student Name :: "<<name<<endl;
    cout<<"Student Roll No. :: "<<roll<<endl;
    cout<<std::flush;
    cout<<"Student Father Name :: "<<fname<<"\n"<<endl;
    Sleep(2000);
    }
    file.close();
}
void temp::searchstudents(){
    file.open(filename,ios::in);
    if(!file.is_open()){
        file.close();
        cout<<"File is Not Created Even !\nCreating..."<<endl;
        Sleep(2000);
        cout<<"File Created Successfully";
        temp::addstudent();
    }
    string roll_;
    cout<<"Enter the Roll no. :: ";getline(cin,roll_);
    int studentFound=0;
    while(getline(file,name,'*')&&getline(file,fname,'*')&&getline(file,roll,'\n')){
    if(roll==roll_){
        cout<<"Found >>"<<endl;
        cout<<"Student Name :: "<<name<<endl;
        cout<<"Student Roll Number :: "<<roll<<endl;
        cout<<"Student's Father Name :: "<<fname<<"\n"<<endl;
        Sleep(2000);
        studentFound=1;
        break;
    }
    }
    file.close();
    if(studentFound==0){
        cout<<"No Student Found With Such Roll No."<<endl;
    }
}