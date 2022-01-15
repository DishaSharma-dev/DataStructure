/* Max Sub Square Matrix with all 0's 
Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. 
You need to return the size of the square matrix with all 0s.
Input : 3 3
1 1 0
1 1 1
1 1 1
Output: 1*/

#include <iostream>
using namespace std;

int maxSquareMatrix(int arr[4][4]){
	int maxi = 0;
	int dp[4][4];
	for(int i = 0; i < 4; i++){
		if(arr[0][i] == 1){
			dp[0][i] = 0;
		}
		else{
			dp[0][i] = 1;
			maxi = 1;
		}
	}
	for(int i = 0; i < 4; i++){
		if(arr[i][0] == 1){
			dp[i][0] = 0;
		}
		else{
			dp[i][0] = 1;
			maxi = 1;
		}
	}
	for(int i = 1; i < 4; i++){
		for(int j = 1; j < 4; j++){
			if(arr[i][j] == 0){
				dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j], dp[i][j-1]));
			}
			else{
				dp[i][j] = 0;
			}
			if(maxi < dp[i][j]){
				maxi = dp[i][j];
			}
		}
	}
	return maxi;
}

int main(){
	int n,m;
	cout<<"Enter the number of rows: ";
	cin>>n;
	cout<<"Enter the number of cols: ";
	cin>>m;
	int arr[4][4];
    for(int i = 0; i < 4; i++){
    	for(int j = 0; j < 4; j++){
    		cin>>arr[i][j];
		}
	}
	cout<<"Output is: ";
	cout<<maxSquareMatrix(arr);
	return 0;
}