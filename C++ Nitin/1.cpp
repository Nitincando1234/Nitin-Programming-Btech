#include<vector>
#include<iostream>
#include"1.h"
using namespace std;

int main(){Vec3D vec1;
    vec1.x=10;
    vec1.y=12;
    vec1.z=25;
    int length=vec1.getLenght();
    cout<<"Lenght of the Vector is = "<<length<<endl;
    return 0;
}