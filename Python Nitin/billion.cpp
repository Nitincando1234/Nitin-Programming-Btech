#include<iostream>
#include<chrono>
using namespace std;

int main(){
    int n = 0;
    auto start = chrono::high_resolution_clock::now();
    while(n < 1000000000000){
        cout<<n<<endl;
        n++;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(end - start);
    cout << n << endl;
    cout << "Time taken: " << duration.count() << " seconds" << endl;
    return 0;
}
