#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;
class temp{
    string filename="libBook.txt";
    fstream file,newAdmin;
    string id,name,author,search,admin,adminAuth;
    public:
    void showAll();
    void getBook();
    void addBook();
};
int main(){
    temp obj;
    int choice;
    while(true){
    cout<<"========================================"<<endl;
    cout<<"1. Show All Books ::"<<endl;
    cout<<"2. Get Book ::"<<endl;
    cout<<"3. Add Book (Admin only) ::"<<endl;
    cout<<"4. Exit ::"<<endl;
    cout<<"========================================"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
        {cin.ignore();
        obj.showAll();
        break;}
        case 2:{
        cin.ignore();
        obj.getBook();
        break;}
        case 3:{
        cin.ignore();
        obj.addBook();
        break;}
        default:
        {cout<<"Wrong Choice\nChoose Again !"<<endl;}
    }}
}
void temp::showAll(){
    file.open(filename,ios::in);
    if(!file.is_open()){
        cout<<"File not found !"<<endl;
    }
    cout<<"\t\tID\t\tBOOK\t\tAUTHOR\t\t"<<endl;
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'*');
    while(!file.eof()){
    cout<<"\t\t"<<id<<"\t\t"<<name<<"\t\t"<<author<<"\t\t"<<endl;
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'*');
    }
    file.close();
}
void temp::getBook(){
    temp::showAll();
    cout<<"Enter the ID ::";
    getline(cin,search);
    if(true){file.open(filename,ios::in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'*');
    while(!file.eof()){
    if(id==search){
        cout<<"Book Found !"<<endl;
        fstream newl;
        string newChar;
        newl.open(id,ios::in);
getline(newl,newChar,'\n');
while(!file.eof()){
cout<<newChar<<endl;
getline(newl,newChar,'\n');
}}
    break;
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'*');
    }file.close();
    }
    else{
        cout<<"File Not Found !"<<endl;
    }
}
void temp::addBook(){
    if(!file.is_open()){
    cout<<"No Enteries Were Created\nCreate An Admin first !"<<endl;
    cout<<"Admin Name ::";getline(cin,admin);
    cout<<"Admin Password ::";getline(cin,adminAuth);
    cout<<"Admin Creation Success !";
    newAdmin.open("newAdmin.txt",ios::out);
    newAdmin<<admin<<'*'<<adminAuth<<endl;
    newAdmin.close();
    exit(0);
    }
    newAdmin.open("newAdmin.txt",ios::in);
    string admin_,adminAuth_;
    cout<<"Admin Name ::";getline(cin,admin_);
    cout<<"Admin Password ::";getline(cin,adminAuth_);
    getline(newAdmin,admin,'*');
    getline(newAdmin,adminAuth,'*');
    while(!newAdmin.eof()){
        if(admin==admin_){
            if(adminAuth==adminAuth_){
                cout<<"Book ID to Add ::";getline(cin,id);
                cout<<"Book Name ::";getline(cin,name);
                cout<<"Author ::";getline(cin,author);
                file.open(filename,ios::out|ios::app);
                file<<id<<'*'<<name<<'*'<<author<<endl;
                file.close();
                break;
            }
        }
    else{
        cout<<"Wrong Password or Admin Name !"<<endl;
        break;
    }
    }
  
}