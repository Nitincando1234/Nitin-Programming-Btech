#include<iostream>
using namespace std;
struct task{
    task* pNext;
    string description;
};
task *pHead,*pCurr;
void queue_task(const string &currDesription){
    task *newTask=new task;
    newTask->description=currDesription;
    newTask->pNext=nullptr;
    if(nullptr==pHead){
    pHead=newTask;
    pCurr=pHead;
    }
    else{
    pCurr->pNext=newTask;
    pCurr=pCurr->pNext;
    }

}
bool remove_head(){//destruction based traversal
    if(nullptr==pHead)
    return false;
    task *pTask=pHead;
    pHead=pHead->pNext;
    delete pTask;
    return (pHead!=nullptr);//true if there are links available in the list
}
void destroyList(){
    while(remove_head()){
        destroyList();
    }
}
task* executeTask(const task *pTask){
    if(pTask==nullptr)return nullptr;
    cout<<"Executing: "<<pTask->description<<endl;
    return (pTask->pNext);
}
void executeAll(){
    task *pTask=pHead;
    while(pTask!=nullptr){
        pTask=executeTask(pTask);
    }
    cout<<"All Tasks completed !"<<endl;
}

int main (){
    queue_task("Plug in the cord");
    queue_task("Start the switch");
    queue_task("Turn on the Computer");
    queue_task("Open VS Code");
    queue_task("Codin...");
    executeAll();
    cout<<endl<<"Cleaning Up the memory !"<<endl;
    destroyList();   
    cout<<endl<<"Memory Freed Successfully !\n"<<endl;
    return 0;
}