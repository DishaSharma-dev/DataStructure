//Rotate matrix by 90 anticlockwise

#include <iostream>
using namespace std;

void rotateArray(int input[][100],int m,int n){
	cout<<"Array after 90 rotation anticlockwise :\n";
	for(int i=m-1;i>=0;i--){
		for(int j=0;j<n;j++){
			cout<<input[j][i]<<" ";
		}
		cout<<endl;
	}
}

void printArray(int input[][100],int m,int n){
	cout<<"Original Matrix is: \n";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<input[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int m,n;
	cout<<"Enter the number of rows: ";
	cin>>m;
	cout<<"Enter the number of columns: ";
	cin>>n;
	int input[100][100];
	cout<<"Enter the elements: ";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>input[i][j];
		}
	}
	printArray(input,m,n);
	rotateArray(input,m,n);
	return 0;
}