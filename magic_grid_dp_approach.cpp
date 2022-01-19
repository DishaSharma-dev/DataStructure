/* Magic Grid TC: m*n
You are given a magic grid A with R rows and C columns. In the cells of the grid, you will either get magic
juice,which increases your strength by |A[i][j]| points, or poison, which takes away
A[i][j]| strength points.
If at any point of the journey, the strength points become less than or equal to zero, then you will die.
Input: 3 4
       0 -2 -3 1
       -1 4 0 -2
       1 -2 -3 0
Output: 2*/

#include <iostream>
using namespace std;

int magicGrid(int** arr, int n, int m){
	int dp[n][m];
	for(int i = n-1; i >= 0; i--){
		for(int j = m-1; j >= 0; j--){
			if(i == n-1 && j == m-1) dp[i][j] = min(0, arr[i][j]);
			else if(i == n-1) dp[i][j] = min(0, arr[i][j] + dp[i][j+1]);
			else if(j == m-1) dp[i][j] = min(0, arr[i][j] + dp[i+1][j]);
			else{
				dp[i][j] = min(0, arr[i][j] + max(dp[i+1][j], dp[i][j+1]));
			}
		}
	}
	return abs(dp[0][0]) + 1;
}

int main(){
	int n,m;
	cout<<"Enter the number of rows: ";
	cin>>n;
	cout<<"Enter the number of columns: ";
	cin>>m;
	int** arr = new int*[n];
	for(int i = 0; i < n; i++){
		arr[i] = new int[m];
		for(int j = 0; j < m; j++){
			cin>>arr[i][j];
		}
	}
	cout<<"Output is: ";
	cout<<magicGrid(arr, n, m);
	return 0;
}