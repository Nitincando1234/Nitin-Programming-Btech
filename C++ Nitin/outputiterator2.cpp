#include<vector>
#include<iostream>
#include<iterator>
using namespace std;
int main(){
    vector<int> myVec={1,2,3,4,5};
    ostream_iterator<int>outing(cout," ");
    copy(myVec.begin(),myVec.end(),outing);

    return 0;
}