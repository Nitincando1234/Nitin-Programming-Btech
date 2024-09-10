#include<iostream>
using namespace std;
class item{
static int count;
int number;
	public:
void getData(int n){number=n;
count++;}
void showCount(){cout<<"count: "<<count<<endl;}
};
int item::count=0;
int main(){
item i;
i.getData(5);
i.getData(6);
i.showCount();
return 0;
}
