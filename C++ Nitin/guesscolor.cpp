#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<ctime>
using namespace std;
enum color {red=0,yellow,green,blue,white};
color generateRandomNumber(){
    return static_cast<color>(rand()%5);
}
color stringToColor(string &c){
    if(c=="red")return red;
    else if(c=="yellow")return yellow;
    else if(c=="green")return green;
    else if(c=="blue")return blue;
    else if(c=="white")return white;
    else return static_cast<color>(-1);//Unknown Color
}
int main(){
    srand(time(0));
    while(true){
    system("cls");
    cout<<"*****************************************"<<endl;
    cout<<"Guess the color (red,yellow,green,blue,white):";
    string guess;
    cin.ignore();
    cin>>guess;
    for(int i=0;i<guess.length();i++){
        guess[i]=tolower(guess[i]);
    }
    color targetColour=generateRandomNumber();
    color userColour=stringToColor(guess);
    if(guess=="red"||guess=="yellow"||guess=="green"||guess=="blue"||guess=="white"){
    if (guess=="red")
    userColour=(color)red;
    else if (guess=="yellow")
    userColour=(color)yellow;
    else if (guess=="green")
    userColour=(color)green;
    else if (guess=="blue")
    userColour=(color)blue;
    else if (guess =="white")
    userColour=(color)white;

    if(userColour==targetColour){
    cout<<"You guessed the right colour !";}
    else{
    cout<<"\nTry Again !";}}
    else
    cout<<"Unknown Colour !";
    Sleep(2000);
    }
    return 0;
}
