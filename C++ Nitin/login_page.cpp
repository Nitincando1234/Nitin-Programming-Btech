#include<string>
#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;
class temp{
    string username,password,email;
    fstream file;
    public:
    void file_opener(){
    file.open("Loginfile.txt",ios::out|ios::app);
    file.close();
    }
    void login();
    void login(string,string,string);
    void creation();
    void forgot(string,string);

};
int main(){
    int choice;temp obj;
    obj.file_opener();
    cout<<"1. Login"<<endl;
    cout<<"2. Create an Account"<<endl;
    cout<<"3. Exit ::"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
        {
            obj.login();
        }
        break;
        case 2:
        {
            obj.creation();
        }
        break;
        case 3:
        break;
        default:
        cout<<"Wrong choice choose Again !"<<endl;
    }
    return 0;
}
void temp::login(string username_, string email_,string password_){
    file.open("Loginfile.txt",ios::in);
    getline(file,username,'*');
    getline(file,email,'*');
    getline(file,password,'*');
    while(!file.eof()){
        if(username_==username){
            if(password==password_)
            cout<<"Login Successful"<<endl;
        }
    getline(file,username,'*');
    getline(file,email,'*');
    getline(file,password,'*');
    }
    cout<<"Welcome to the App !"<<endl;
    file.close();
    exit;
}
void temp::forgot(string username_,string email_){
    getline(file,username,'*');
    getline(file,email,'*');
    getline(file,password,'*');
    while(!file.eof()){
        if(username_==username){
           if(email_==email){
    file.open("Loginfile.txt",ios::out|ios::app);
    fflush(stdin);
    cout<<"New Password (Type 'h' for Help::) ::";
    getline(cin,password);
    if(password=="h"){
        cout<<"Your Password Should Contain atleast 4 characters, and\n(Optional) special characters and numbers for better security ."<<endl;
    }
    if(password.length()<4){
        cout<<"Length of the Password Should be more than 4 characters, Try Again !"<<endl;
        temp::creation();
    }
    file<<username<<'*'<<email<<'*'<<password<<'*'<<endl;
    cout<<"Password Updated Successfully."<<endl;
    file.close();
    break;
           }
        }
    getline(file,username,'*');
    getline(file,email,'*');
    getline(file,password,'*');
    }
    if(username_!=username)
    cout<<"Username Not Found !"<<endl;
    else
    temp::login(username,email,password);
}
void temp::login(){
    string email_;
    file.open("Loginfile.txt",ios::in);
    if(file.eof()){
    cout<<"No Users Created \1"<<endl;
    }
    string username_,password_;
    cout<<"--------LOGIN------------"<<endl;
    cout<<"1. Login\n2. Forgot Password ::"<<endl;
    int choice;
    cin>>choice;
    cout<<"Username ::";fflush(stdin);getline(cin,username_);
    if(choice==1){
    cout<<"Password ::";getline(cin,password_);
    getline(file,username,'*');
    getline(file,email,'*');
    getline(file,password,'*');
    while(!file.eof()){
        if(username_==username){
            if(password==password_)
            cout<<"Login Successful"<<endl;
            break;
        }
    getline(file,username,'*');
    getline(file,email,'*');
    getline(file,password,'*');
    }
    if(username!=username|password!=password_){
        cout<<"Login Failed, Try Again !"<<endl;
        temp::login();}
    cout<<"Welcome to the App !"<<endl;
    file.close();}
    else if(choice==2){getline(file,username,'*');
    getline(file,email,'*');
    getline(file,password,'*');
    while(!file.eof()){
        if(username_==username){
            break;
        }
    getline(file,username,'*');
    getline(file,email_,'*');
    getline(file,password,'*');
    }
        temp::forgot(username_,email_);}
    else{
        cout<<"Login Failed, Try Again !"<<endl;
        temp::login();
    }
    exit;
}
void temp::creation(){
    file.open("Loginfile.txt",ios::out|ios::app);
    cout<<"-------CREATION----------"<<endl;
    fflush(stdin);
    cout<<"Email ID ::";
    fflush(stdin);
    getline(cin,email);
    cout<<"Username ::";
    fflush(stdin);
    getline(cin,username);
    cout<<"Password (Type 'h' for Help::) ::";
    fflush(stdin);
    getline(cin,password);
    if(password=="h"){
        cout<<"Your Password Should Contain atleast 4 characters, and\n(Optional) special characters and numbers for better security ."<<endl;
    }
    if(password.length()<4){
        cout<<"Length of the Password Should be more than 4 characters, Try Again !"<<endl;
        temp::creation();
    }
    {file<<username<<'*'<<email<<'*'<<password<<'*'<<endl;
    cout<<"Account Created Successfully."<<endl;
    file.close();}
    temp::login(username,email,password);
}
