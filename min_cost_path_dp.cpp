/* Minimum Cost Path (DP Approach) */

#include <iostream>
using namespace std;

int minCost(int** arr, int n){
	int**  dp = new int* [n];
	for(int i = 0; i < n; i++){
		dp[i] = new int[n];
	}
	dp[n-1][n-1] = arr[n-1][n-1];
	for(int i = n-2; i >= 0; i--){
		dp[i][n-1] = dp[i+1][n-1] + arr[i][n-1];
	}
	for(int j = n-2; j >= 0; j--){
		dp[n-1][j] = dp[n-1][j+1] + arr[n-1][j];
	}
	for(int i = n-2; i >= 0; i--){
		for(int j = n-2; j >= 0; j--){
			dp[i][j] = arr[i][j] + min(dp[i+1][j], min(dp[i+1][j+1], dp[i][j+1]));
		}
	}
	int ans = dp[0][0];
	for(int i = 0; i < n; i++){
		delete []dp[i];
	}
	delete []dp;
	return ans;
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
	cout<<minCost(arr, n);
	for(int i = 0; i < n; i++){
		delete []arr[i];
	}
	delete []arr;
	return 0;
}