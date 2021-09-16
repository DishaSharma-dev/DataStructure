/*Find an element in 2d array whose element are sorted row and col wise

Bruteforce Approach: Search and compare with each element in matrix =>0n^2
Next Approach: We can apply binary search to each element either row or col wise => nlogn or mlogm
finest Approact: Starting from rightest ele in array and move accorindgly the element with left or bottom => 0(m+n)
*/

#include <iostream>
using namespace std;

void findElement(int input[][100], int m, int n, int x){
	int i = 0;
	int j = n-1;
	while(i < m && j >= 0){
		if(input[i][j] == x){
			cout<<i<<" "<<j;
			return;
		}
		else if(input[i][j] < x){
		    i++;	
		}
		else{
			j--;
		}
	}
	cout<<"-1"<<endl;
}

void printArray(int input[][100], int m, int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<input[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int m,n,x;
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
	cout<<"Enter the element to find: ";
	cin>>x;
	findElement(input,m,n,x);
}