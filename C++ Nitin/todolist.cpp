#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<windows.h>
using namespace std;
int ID;
struct todolist{
    int tid;
    string todo;
};
void banner();
void addTask();
void showTask();
void searchTask();
void deleteTask();
void updateTask();
int main(){
    int choice;
    ifstream fin;
    fin.open("todo.txt");
    fin>>ID;
    fin.close();
    while(true){
    system("clear");
    banner();
    cout<<"\t1. Add Task: \n";
    cout<<"\t2. Show Tasks: \n";
    cout<<"\t3. Search Task: \n";
    cout<<"\t4. Delete Task: \n";
    cout<<"\t5. Update Task: \n";
    cout<<"\t6. Exit: \n";
    cout<<"\tEnter Your Choice: ";
    cin>>choice;
    if(choice==1)addTask();
    else if(choice==2)showTask();
    else if(choice==3)searchTask();
    else if(choice==4)deleteTask();
    else if(choice==5)updateTask();
    else if(choice==6)break;
    else{ 
    system("clear");
    banner();
    cout<<"\tWrong Choice, Try Again !"<<endl;
    Sleep(1500);
    }}
    return 0;
}
void banner(){
    system("CLS");
    cout<<"______________________________________________________"<<endl;
    cout<<"                    My ToDo"<<endl;
    cout<<"______________________________________________________"<<endl;
}
void addTask(){
    banner();
    char choice;
    todolist todoobj;
    ofstream fout;
    system("clear");
    banner();
    cout<<"\tEnter The Task: ";
    cin.get();
    getline(cin,todoobj.todo);
    cout<<"\tSave: (y/n) ";
    cin>>choice;
    if(choice=='y'){
        ID+=1;
        fout.open("todo.txt",ofstream::app|ofstream::out);
        todoobj.tid=ID;
        fout<<todoobj.tid<<endl;
        fout<<todoobj.todo<<endl;
        cout<<"\tSaved !"<<endl;
        cout<<"\tAdd More Tasks ?: (y/n) ";
        cin>>choice;
        fout.close();
        if(choice=='y')
        addTask();
        else
        return;
    }
    else{
        return;
    }

}
void showTask(){
    system("clear");
    banner();
    ifstream fin;
    fin.open("todo.txt");
    todolist todoobj;
    cout<<"\tTasks: \n";
    while(fin>>todoobj.tid){
    fin.ignore();
    getline(fin,todoobj.todo);
    if(todoobj.todo!=""){
    cout<<"\t"<<todoobj.tid<<". "<<todoobj.todo<<endl;
    }
    else{
    cout<<"Empty! ";
    }
    }
    fin.close();
    char choice;
    cout<<"\tExit: (y/n) ";
    cin>>choice;
    if(choice!='y')
    showTask();
    system("cls");
}
void searchTask(){
    system("cls");
    banner();
    showTask();
    system("cls");
    banner();
    cout<<"\tEnter the Id of the Task: ";
    int id,found=0;
    char choice;
    cin>>id;
    ifstream fin;
    todolist todoobj;
    fin.open("todo.txt");
    while(!fin.eof()){
    fin>>todoobj.tid;
    fin.ignore();
    getline(fin,todoobj.todo);
    if(todoobj.tid==id){
    found=0;
    break;
    }
    }
    if(found==0){
    banner();
    cout<<"\t"<<todoobj.tid<<". Found Task: "<<todoobj.todo<<endl;
    }
    else{
    banner();
    cout<<"\tNot Found The Task! "<<endl;
    }
    cout<<"\tExit: (y/n) ";
    cin>>choice;
    if(choice=='y')return;
    else
    searchTask();
    fin.close();
}
void deleteTask(){
    ifstream fin;
    ofstream temp;
    int id,idTemp=0;
    todolist todoobj;
    fin.open("todo.txt");
    temp.open("temp.txt");
    banner();
    cout<<"\tEnter the Id of Task: ";
    cin>>id;
    while(fin>>todoobj.tid){
    fin.ignore();
    getline(fin,todoobj.todo);
    if(todoobj.tid!=id){
    idTemp+=1;
    temp<<idTemp<<endl;
    temp<<todoobj.todo<<endl;
    }
    }
    fin.close();
    temp.close();
    remove("todo.txt");
    rename("temp.txt","todo.txt");
    ID--;
    system("cls");
    showTask();
}
void updateTask(){
    ifstream fin;
    ofstream temp;
    string task;
    int id,idTemp=0;
    todolist todoobj;
    fin.open("todo.txt");
    temp.open("temp.txt");
    banner();
    cout<<"\tEnter the Id of Task to Modify: ";
    cin>>id;
    cout<<"\tEnter the Task: ";
    cin.ignore();
    getline(cin,task);
    while(fin>>todoobj.tid){
    fin.ignore();
    getline(fin,todoobj.todo);
    if(todoobj.tid!=id){
    idTemp+=1;
    temp<<idTemp<<endl;
    temp<<todoobj.todo<<endl;
    }
    else{
    idTemp+=1;
    temp<<idTemp<<endl;
    temp<<task<<endl;
    }
    }
    fin.close();
    temp.close();
    remove("todo.txt");
    rename("temp.txt","todo.txt");
    system("cls");
    showTask();
}