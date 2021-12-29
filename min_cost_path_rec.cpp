// Minimum CosT Path

//Recursive Approach (Time Complexity => 3^n)

#include <iostream>
using namespace std;

int minCost(int** arr, int s1, int s2, int e1, int e2){
	if(s1 == e1 && s2 == e2){
		return arr[e1][e2];
	}
	if(s1 > e1 || s2 > e2){
		return INT_MAX;
	}
	int option1 = minCost(arr, s1, s2 + 1, e1, e2);
	int option2 = minCost(arr, s1 + 1, s2 + 1, e1, e2);
	int option3 = minCost(arr, s1 + 1, s2, e1, e2);
	return arr[s1][s2] + min(option1, min(option2, option3));
}

int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int** arr = new int* [n];
	for(int i = 0; i < n; i++){
		arr[i] = new int[n];
		for(int j = 0; j < n; j++){
			cin>>arr[i][j];
		}	
	}
	cout<<"Array is: ";
	for(int i = 0; i < n; i++){
		for(int j =0; j < n; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Minimum Cost Path is: ";
	cout<<minCost(arr, 0, 0, n-1, n-1);
	for(int i = 0; i < n; i++){
		delete []arr[i];
	}
	delete []arr;
	return 0;
}