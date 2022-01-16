/* Ways to make coin change
For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}.
You need to figure out the total number of ways W, in which you can make the change for Value V
using coins of denominations D.
Return 0 if the change isn't possible.
Input: 3
       1 2 3
       4
Output: 4
*/

#include <iostream>
using namespace std;

int coinChange(int* arr, int n, int v){
	int dp[v+1] = {0};
	dp[0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = arr[i]; j <= v; j++){
			dp[j] += dp[j - arr[i]];
		}
	}
	return dp[v];
}

int main(){
	int n;
	int v;
	cout<<"Enter the size of array: ";
	cin>>n;
	cout<<"Enter the values: ";
	int arr[n];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	cout<<"Enter the value: ";
	cin>>v;
	cout<<"Output is: ";
	cout<<coinChange(arr, n, v);
	return 0;
}