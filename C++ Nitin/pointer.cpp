#include <iostream>
using namespace std;
struct task{
    task *pNext;
    string description;
};
int main(){
    task item;
    item.description="Do something !";
    cout<<item.description<<endl;
    task *NewTask=new task;
    NewTask->description="Do something else !";
    cout<<NewTask->description<<endl;
    delete NewTask;
    return 0;
}