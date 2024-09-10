#include<iostream>
#include <stdexcept>
using namespace std;
void test() throw(int,char,runtime_error){
    cout<<"I will throw a Runtime Error.\1"<<endl;
    throw std::runtime_error("thrown runtime error woho0....");
}
int main(){
    try{ test();}
    catch (char){}
    catch (runtime_error t){
        cout<<"Runtime Error: "<<t.what()<<endl;
    }
    catch (int){}
    return 0;
}