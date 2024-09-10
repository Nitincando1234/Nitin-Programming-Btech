#include<cmath>
#include<iostream>
using namespace std;
class date{
    int a,b,c;
    public:
    date(){}
    date(int date,int month,int year){a=date;b=month;c=year;}
    int month_even();
    int leap_year();
    int verify_all();
    int verify();
    void boost(int);
    void print();
};
int main(){
    int date1,month,year,booster,choice;
    cout<<"Enter the date:(DD/MM/YYYY) ";
    cin>>date1>>month>>year;
    date d(date1,month,year);
    if(d.verify()){
    d.print();
    cout<<"How many days to increment: ";
    cin>>booster;
    cout<<"What Operation \n1.Add\n2.Subtract\n:";
    cin>>choice;
    switch(choice){
    case 1:{
        d.boost(booster);break;
    }
    case 2:{
        d.boost(-booster);break;
    }
    default:
    cout<<"Wrong choice !"<<endl;
    }
}
    return 0;
}
int date::month_even(){
    if(b%2==0)
    return 1;
    else
    return 0;
}
int date::leap_year(){
    if(c%4==0)
    return 1;
    else
    return 0;
}
int date::verify_all(){
    if(a<0 && b<0 && c<0)
    return 1;
    else 
    return 0;
}
int date::verify(){
    if(date::verify_all()){
    cout<<"Zero Enteries for DD/MM/YYYY is not allowed !"<<endl;
    return 0;}
    if(b==2){
    if(date::leap_year()){
    if(a>29)
    {
    cout<<"Date cannot exceed 29 for a leap year month !"<<endl;
    return 0;
    }
    }
    else{
    if(a>28){
    cout<<"Date cannot exceed 28 for a non-leap year month !"<<endl;
    return 0;
    }
    }}
    else{
    if(date::month_even()){
    if(a>30)
    {
    cout<<"Date cannot exceed 30 for an even month !"<<endl;
    return 0;
    }
    }
    else{
    if(a>31){
    cout<<"Date cannot exceed 31 for an odd month !"<<endl;
    return 0;
    }
    }
    }
    return 1;
}
void date::boost(int days){
    int tempYear,temp;
    if(days==0)return;
    if(month_even()){
    if(leap_year())tempYear=round(days%366);
    else tempYear=round(days)/365;
    c+=tempYear;
    temp=round(days/31)+1;
    if(b==2){
    if(leap_year())
    a=((a+days)%29)-2;
    else
    a=((a+days)%28)+2;
    }
    //not feb
    else{
    a=(a+days)%31+1;
    }
    b=(b+temp)%12;
    // if(b==2){
    // if(leap_year()){
    // if(days%31>2){
    // b++;
    // boost(days%31);}
    // }else{if(days%31>3){b++;boost(days%31);}}
    // }
    if(b==12)
    }

    else{
    if(leap_year())tempYear=round(days/366);
    else tempYear=round(days)/365;
    c+=tempYear;
    temp=round(days/30);
    b=(b+temp)%12;
    a=(a+days)%30-1;
    }
    date::print();
}
void date::print(){
    cout<<a<<"/"<<b<<"/"<<c<<endl;
}