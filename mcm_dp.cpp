/* Matrix Chain Multiplication (DP Approach) (TC = n^2)
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices.
In other words, determine where to place parentheses to minimize the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i].
You need to find minimum number of multiplications needed to multiply the chain.

Input: 3
       10 15 20 25
Output: 8000
Explanation: There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.
If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000. */

#include <iostream>
using namespace std;

int mcm(int* arr, int n){
    int dp[n][n];
	for(int g = 0; g < n; g++){
		for(int i = 0, j = g; j < n; i++, j++){
			if(g == 0){
				dp[i][j] = 0;
			}
			else if(g == 1){
				dp[i][j] = arr[i] * arr[j] * arr[j+1];
			}
			else{
				int min = INT_MAX;
				for(int k = i; k < j; k++){
					int lc = dp[i][k]; // left part
					int rc = dp[k+1][j]; // right part
					int mc = arr[i] * arr[k+1] * arr[j + 1]; // cost of operation
					int tc = lc + rc + mc;
					if(tc < min){
						min = tc;
					}
				}
				dp[i][j] = min;
			}
		}
	}
	return dp[0][n-1];
}

int main(){
	int n;
	cout<<"Enter the value of n: ";
	cin>>n;
	int arr[n+1];
	cout<<"Enter the values in an array: ";
	for(int i = 0; i <= n; i++){
		cin>>arr[i];
	}
	cout<<mcm(arr, n);
	return 0;
} 