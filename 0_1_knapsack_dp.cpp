/* 0 1 Knapsack (DP Approach) o n^2 time complexity
A thief is robbing a store and can carry a maximal weight of W into his knapsack. 
There are N items and ith item weighs wi and is of value vi.
Considering the constraints of maximum weight that knapsack can carry,
you have to find and return the maximum value that thief can generate by stealing items.
Input: 4
1 2 4 5
5 4 8 6
5
Output: 13*/

#include <iostream>
using namespace std;

int knapsack(int* weight, int* values, int n, int max_weight){
	int m = max_weight + 1;
	n = n+1;
	int dp[n][m];
	for(int i = 0; i < m; i++){
		dp[0][i] = 0;
	}
	for(int i = 0; i < n; i++){
		dp[i][0] = 0;
	}
	for(int i = 1; i < n; i++){
		for(int j = 1; j < m; j++){
			if(j - weight[i-1] < 0){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = max((values[i-1] + dp[i-1][j - weight[i-1]]), dp[i-1][j]);
			}
		}
	}
	return dp[n-1][m-1];
}

int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int max_weight;
	int weight[n];
	int values[n];
	cout<<"Enter the values of weight: ";
	for(int i = 0; i < n; i++){
		cin>>weight[i];
	}
	cout<<"Enter the values of val: ";
	for(int i = 0; i < n; i++){
		cin>>values[i];
	}
	cout<<"Enter the maximum weight: ";
	cin>>max_weight;
	cout<<"Output is: ";
	cout<<knapsack(weight, values, n, max_weight);
	return 0;
}