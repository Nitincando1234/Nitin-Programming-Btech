#include<iostream>
using namespace std;
void readline(char * arr,int delim,int length){
   int cnt=0;
   char ch;
 
   while(true){   ch=cin.get();arr[cnt]=ch;
      if (ch== delim||ch==length -1){break;}
    
      cnt++;
   
   }    arr[cnt]='\n'; cout<<cnt<<endl;
}
int main(){
   char arr[100];

   readline(arr,'\n',100);
cout<<arr<<endl;
   return 0;
}