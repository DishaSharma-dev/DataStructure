/* Loot Houses
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. 
Find the maximum amount of money he can loot.
Input: 6
       5 5 10 100 10 5
Output: 110
*/

#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int arr[n];
	int dp[n];
	cout<<"Enter the elements in an array: ";
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	dp[0] = arr[0];
	dp[1] = max(arr[0],arr[1]);
	for(int i = 2; i < n; i++){
		dp[i] = max((arr[i] + dp[i-2]),dp[i-1]);
	}
	cout<<dp[n-1];
	return 0;
}