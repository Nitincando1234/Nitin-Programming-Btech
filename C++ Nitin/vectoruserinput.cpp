#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter the size of the vector you want: ";
    int size,x;
    cin>>size;
    vector<int>myVec;
    for(int i=0;i<size;i++){
        cout<<"Enter the "<<i+1<<" Element: ";
        cin>>x;
        myVec.push_back(x);
    }
    for(vector<int> ::iterator it=myVec.begin();it!=myVec.end();it++){
        cout<<*it<<endl;
    }
    cout<<myVec.capacity()<<endl;
    myVec.clear();
    cout<<myVec.size()<<endl;
    return 0;
}