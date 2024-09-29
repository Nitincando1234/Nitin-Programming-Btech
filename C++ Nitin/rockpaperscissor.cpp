#include <iostream>
#include <cstdlib>
using namespace std;
#define ROCK 1
#define PAPER 2
#define SCISSOR 3
void rps(){
    int userMove,computerMove;
   while(1){
        cout<<"Enter your Move: 1)Rock 2) Paper 3) Scissor : ";
        cin>>userMove;
        if(userMove==ROCK || userMove==PAPER || userMove ==SCISSOR)
        break;
        else
        cout<<"Bad Move/Input! Choose it again."<<endl;
    }
    computerMove=rand()%3+1;
    if(computerMove==1)
    computerMove=ROCK;
    if(computerMove==2)
    computerMove=PAPER;
    if(computerMove==2)
    computerMove=SCISSOR;

    if(userMove==ROCK){
        if(computerMove==ROCK)
        cout<<"Computer Chose Rock. Tie !"<<endl;
        else if(computerMove==SCISSOR)
        cout<<"Computer Chose Scissor. You Win !"<<endl;
        else
        cout<<"Computer Chose Paper. You Lose 1"<<endl;
    }
    else if(userMove==PAPER){
        if(computerMove==PAPER)
        cout<<"Computer Chose Paper. Tie !"<<endl;
        else if(computerMove==SCISSOR)
        cout<<"Computer Chose Scissor. You Lose !"<<endl;
        else
        cout<<"Computer Chose Paper. You Win !"<<endl;
    }
    else if(userMove==SCISSOR){
        if(computerMove==SCISSOR)
        cout<<"Computer Chose Scissor. Tie !"<<endl;
        else if(computerMove==ROCK)
        cout<<"Computer Rock . You Lose !"<<endl;
        else
        cout<<"Computer Chose Paper. You Win !"<<endl;
    }
}
int main(){
    rps();
    int option;
    while(1){
    cout<<"Want to Continue:\n 1) Yes \n 2) No\t:";
    cin>>option;
    if(option==1)
    rps();
    else 
    break;}
    return 0;
}