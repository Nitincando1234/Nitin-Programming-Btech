#include<iostream>
using namespace std;
int wavePrint(int arr[][100],int rows,int cols){for(int col=0;col<cols;col++){
  if(col %2==0)
  {for (int row=0;row<=rows-1;row++){
    cout<<arr[row][col];
  }
  }else {for (int row=rows-1;row>=0;row--){cout<< arr[row][col];}}
  }cout<<endl;
}
int main (){
  int arr[100][100];
  int rows;int cols;
  cin>>rows;
  cout<<"*";
  cin>>cols;
  for (int i=0;i<rows;i++){
    for (int j=0;j<cols;j++){
      cin >>arr[i][j];

    }
  }
   for (int i=0;i<rows;i++){
    for (int j=0;j<cols;j++){
      cout<<arr[i][j];
      
    }cout<<endl;
  }
  wavePrint(arr,rows,cols);
  return 0;

}