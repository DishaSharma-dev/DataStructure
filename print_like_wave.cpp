/*
  print like a wave
  1 2 3 4
  9 8 7 6
  5 0 1 2
  output => 1 9 5 0 8 2 3 7 1 2 6 4
*/
#include <iostream>
using namespace std;

int main(){
	int m,n;
	cout<<"Enter the rows of matrix: ";
	cin>>m;
	cout<<"Enter the cols of matrix: ";
	cin>>n;
	int arr[100][100];
	cout<<"Enter the elements: ";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	cout<<"Output is: ";
	for(int j=0;j<n;j++){
		if(j%2 == 0){
			for(int i=0;i<m;i++){
				cout<<arr[i][j]<<" ";
			}
		}
		else{
			for(int i=m-1;i>=0;i--){
				cout<<arr[i][j]<<" ";
			}
		}
	}
	return 0;
}