/*
  print spiral
  1 2 3 4
  9 8 7 6
  5 0 1 2
  4 2 9 8
  output => 1 2 3 4 6 2 8 9 2 4 5 9 8 7 1 0
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
	int left = 0;
	int right = n-1;
	int top = 0;
	int bottom = m-1;
	while(top <= bottom && left <= right){
		for(int i = left; i <= right; i++){
			cout<<arr[top][i]<<" ";
		}
		top++;
		for(int i = top; i <= bottom; i++){
			cout<<arr[i][right]<<" ";
		}
		right--;
		if(top <= bottom){
			for(int  i = right; i >= left; i--){
				cout<<arr[bottom][i]<<" ";
			}
			bottom--;
		}
		if(left <= right){
			for(int  i = bottom; i>=top; i--){
				cout<<arr[i][left]<<" ";
			}
			left++;
	    }
}
	return 0;
}