/* Minimum Count
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
Input: 4
Output: 1
Explanation: That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. 
The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
*/

#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number: ";
	cin>>n;
	cout<<"Output is: ";
	int dp[n+1];
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2; i <= n; i++){
		dp[i] = INT_MAX;
		for(int j = 1; i - (j*j ) >= 0; ++j){
			dp[i] = min(dp[i], dp[i - (j*j)]);
		}
		dp[i] += 1;
	}
	cout<<dp[n];
	return 0;
}
