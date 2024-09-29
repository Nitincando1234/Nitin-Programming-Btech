#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
void create(){
	cout<<"..................Create Account................\n";
	fstream file;
	string name,fname,amount="",address,ac;
	cout<<"\tEnter your Name:: ";cin.ignore();
	getline(cin,name);
	cout<<"\tEnter your Father Name:: ";
	getline(cin,fname);
	cout<<"\tEnter Your Address:: ";
	getline(cin,address);
	srand(time(0));
	int acTemp=0;
    while (acTemp<1000000000) {
        acTemp = acTemp * 10 + ((rand()*rand()) % 10);
    }
    ac=to_string(acTemp);
	cout<<"\tAccount Creation Success .\n";
	cout<<"\tYour a/c no.:"<<ac<<'\n'<<"Please Save it for future reference \1."<<endl;
    if(amount=="")amount="0";
	file.open("new.txt",ios::app|ios::out);	file<<name<<'\t'<<fname<<'\t'<<ac<<'\t'<<amount<<'\t'<<address<<endl;
	file.close();
	}
    int search(){
    string name,ac,fname,amount,address;
	cout<<"..................Search An Account................\n";
    fstream file;file.open("new.txt",ios::in);
    if(!file.is_open()){
    cout<<"No Account are Created\nContact the Administrator !"<<endl;
    return 0;
    }
    cout<<"Enter the Account Number to Search:: ";
    string search;
    cin>>search;bool found=false;
    getline(file,name,'\t');
    getline(file,fname,'\t');
    getline(file,ac,'\t');
    getline(file,amount,'\t');
    getline(file,address,'\n');
    cout<<ac<<endl;
    while(!file.eof()){
        if(ac==search){
        found=true;
        break;}
    getline(file,name,'\t');
    getline(file,fname,'\t');
    getline(file,ac,'\t');
    getline(file,amount,'\t');
    getline(file,address,'\n');
    }
    file.close();
    if(found==true)
    {cout<<'\t'<<"Name"<<'\t'<<"Father Name"<<'\t'<<"Account Number"<<'\t'<<"Amount"<<'\t'<<"Address"<<endl;
    cout<<'\t'<<name<<'\t'<<fname<<'\t'<<ac<<'\t'<<amount<<'\t'<<address<<endl;
    return 1;}
    else{
    cout<<"Account not found !"<<endl;
    return 0;}
    }
    void Deposit(){
    string search,searchAc,money;
    string name,ac,fname,amount,address;
	cout<<"..................Deposit Money................\n";
    fstream file,file1;file.open("new.txt",ios::in);
    file1.open("new1.txt",ios::out|ios::app);
    if(!file.is_open()){
    cout<<"\tNo Accounts are created \nContact the Administartor\10 !"<<endl;return;}
    cout<<"\tEnter the Account Number:: ";
    cin>>search;
    cout<<"\tEnter the Money To Deposit:: ";cin>>money;
    bool found=false;
    getline(file,name,'\t');
    getline(file,fname,'\t');
    getline(file,ac,'\t');
    getline(file,amount,'\t');
    getline(file,address,'\n');
    cout<<ac<<endl;
    int tempmoney;
    while(!file.eof()){
        if(ac==search){
        tempmoney=stoi(amount,nullptr)+stoi(money,nullptr);
        file1<<name<<'\t'<<fname<<'\t'<<ac<<'\t'<<to_string(tempmoney)<<'\t'<<address<<endl;
        found=true;}
        else{
        file1<<name<<'\t'<<fname<<'\t'<<ac<<'\t'<<amount<<'\t'<<address<<endl;
        }
    getline(file,name,'\t');
    getline(file,fname,'\t');
    getline(file,ac,'\t');
    getline(file,amount,'\t');
    getline(file,address,'\n');
    }
    file.close();file1.close();
    remove("new.txt");
    rename("new1.txt","new.txt");
    if(found==true)
    {cout<<'\t'<<"Name"<<'\t'<<"Father Name"<<'\t'<<"Account Number"<<'\t'<<"Amount"<<'\t'<<"Address"<<endl;
    cout<<'\t'<<name<<'\t'<<fname<<'\t'<<ac<<'\t'<<amount<<'\t'<<address<<endl;}
    else
    cout<<"\nAccount not found !"<<endl;
    }
    void Withdraw(){
    string search,searchAc,money;
    string name,ac,fname,amount,address;
	cout<<"..................Withdraw Money................\n";
    fstream file,file1;file.open("new.txt",ios::in);
    file1.open("new1.txt",ios::out|ios::app);
    if(!file.is_open()){
    cout<<"\tNo Accounts are created \nContact the Administartor\10 !"<<endl;return;}
    cout<<"\tEnter the Account Number:: ";
    cin>>search;
    cout<<"\tEnter the Money To Withdraw:: ";cin>>money;
    bool found=false;
    getline(file,name,'\t');
    getline(file,fname,'\t');
    getline(file,ac,'\t');
    getline(file,amount,'\t');
    getline(file,address,'\n');
    cout<<ac<<endl;
    int tempmoney;
    while(!file.eof()){
        if(ac==search){
        tempmoney=stoi(amount,nullptr)-stoi(money,nullptr);
        if(tempmoney<0){
        file1<<name<<'\t'<<fname<<'\t'<<ac<<'\t'<<amount<<'\t'<<address<<endl;
        cout<<"\tNo Enough Balance in Your Account: "<<ac<<endl;
        found=true;
        }else{
        file1<<name<<'\t'<<fname<<'\t'<<ac<<'\t'<<to_string(tempmoney)<<'\t'<<address<<endl;
        found=true;}}
        else{
        file1<<name<<'\t'<<fname<<'\t'<<ac<<'\t'<<amount<<'\t'<<address<<endl;
        }
    getline(file,name,'\t');
    getline(file,fname,'\t');
    getline(file,ac,'\t');
    getline(file,amount,'\t');
    getline(file,address,'\n');
    }
    file.close();file1.close();
    remove("new.txt");
    rename("new1.txt","new.txt");
    if(found==true)
    {cout<<'\t'<<"Name"<<'\t'<<"Father Name"<<'\t'<<"Account Number"<<'\t'<<"Amount"<<'\t'<<"Address"<<endl;
    cout<<'\t'<<name<<'\t'<<fname<<'\t'<<ac<<'\t'<<amount<<'\t'<<address<<endl;}
    else
    cout<<"\tAccount not found !"<<endl;
    }
    void showbalance()
    {string name,ac,fname,amount,address,search;
	cout<<"..................View Account Balance................\n";
    cout<<"\tEnter the Account Number:: ";
    cin>>search;
    bool found=false;
    fstream file;
    getline(file,name,'\t');
    getline(file,fname,'\t');
    getline(file,ac,'\t');
    getline(file,amount,'\t');
    getline(file,address,'\n');
    file.open("new.txt",ios::in);
    while(!file.eof()){
    if(ac==search){
        found=true;
        break;
    }
    getline(file,name,'\t');
    getline(file,fname,'\t');
    getline(file,ac,'\t');
    getline(file,amount,'\t');
    getline(file,address,'\n');
    }
    file.close();
    if(found==true){
    cout<<'\t'<<"Name"<<'\t'<<"Father Name"<<'\t'<<"Account Number"<<'\t'<<"Amount"<<'\t'<<"Address"<<endl;
    cout<<'\t'<<name<<'\t'<<fname<<'\t'<<ac<<'\t'<<amount<<'\t'<<address<<endl; 
    }
    else{
    cout<<"Account Not Found !"<<endl;
    }
    }
int main(){int choice;
    while(1){
    cout<<"\n\n\n\t::::::::::::::::::::::::::"<<endl;
	cout<<"\t::1.Creation\t\t::\n\t::2.Search Account\t::\n\t::3.Deposit\t\t::\n\t::4.Withdraw\t\t::\n\t::5.Show Balance\t::\n\t::6 or /o/w. Exit\t::"<<endl; 
	cout<<"\t::   Enter Your Choice  :: "<<endl;
    cout<<"\t::::::::::::::::::::::::::"<<endl;
	cin>>choice;
	switch(choice){
		case 1:{create();break;}
        case 2:{search();break;}
        case 3:{Deposit();break;}
        case 4:{Withdraw();break;}
        case 5:{showbalance();break;}
		default:
		cout<<"Wrong Choice !"<<endl;
        return 0;
		}}
	return 0;}