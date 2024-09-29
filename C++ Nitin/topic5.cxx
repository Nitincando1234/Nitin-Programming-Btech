#include<iostream>
using namespace std;
class Car{
public:
Car();
void accelerate();
void speedShow();
static int whichCarFaster(Car car_a, Car car_b);
private:
float speed{0.0f};	};
Car::Car():speed(0.0f){}
void Car::accelerate(){
	speed +=.8f;}
void Car::speedShow(){
	cout<<speed<<endl;}
int Car::whichCarFaster(Car car_a, Car car_b){
if(car_a.speed>car_b.speed){
	return 0;}
	return 1;}

	int main(){
Car car1,car2;

car1.accelerate();
cout<<"Speed of Car 1: ";car1.speedShow();
car2.accelerate();
car2.accelerate();
cout<<"Speed of Car 2:";car2.speedShow();
int result=Car::whichCarFaster(car1,car2);
if(result==0){
	cout<<"1 Car is Faster than 2 Car."<<endl ;}
if(result==1){
	cout<<"1 Car is Slower than 2 Car."<<endl;}
	}
