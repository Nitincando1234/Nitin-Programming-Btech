#include<iostream>
using namespace std;
int roundTenth(int num){
    int rem=num%10;
    if(rem<5){
        return num-=rem;
    }
    else if(rem ==5){
        return num-=rem;
    }
    else{
        num+=rem;
        rem=num%10;
        num-=rem;
        return num;
    }
}
int roundHundredth(int num){
    int rem=num%100;
    if(rem<50){
        return num-=rem;
    }
    else if(rem ==50){
        return num-=rem;
    }
    else{
        num+=rem;
        rem=num%100;
        num-=rem;
        return num;
    }
}
int roundThousandth(int num){
    int rem=num%1000;
    if(rem<500){
        return num-=rem;
    }
    else if(rem ==500){
        return num-=rem;
    }
    else{
        num+=rem;
        rem=num%1000;
        num-=rem;
        return num;
    }
}
int roundInteger(float num){
    num *=10;
    int rem=(int)num%10;
    if(rem<5){
     num-=rem;
     return num/10;
    }
    else if(rem ==5){
     num-=rem;
     return num/10;
    }
    else{
        num+=rem;
        rem=(int) num%10;
        num-=rem;
        return num/10;
    }
}
int main(){
    float num;
    cout<<"Enter the number: ";
    cin>>num;
    cout<<"Original Number: "<<num<<endl;
    cout<<"Rounded to Integer: "<<roundInteger(num)<<endl;
    if(num>=0 && num<100 ){
    cout<<"Rounded to The nearest tenth: "<<roundTenth((int) num)<<endl;}
    else if(num>100 && num<1000){
    cout<<"Rounded to The nearest hundredth: "<<roundHundredth((int) num)<<endl;}
    else{
    cout<<"Rounded to The nearest thousandth: "<<roundThousandth((int) num)<<endl;}

    return 0;
}