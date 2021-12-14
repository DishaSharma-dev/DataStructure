/* Minimum Number of chocolates
Miss. Noor Rashid is a teacher. She wants to give some chocolates to the students in her class. 
All the students sit in a line, and each of them has a score according to performance. 
Noor wants to give at least one chocolate to each student. She distributes chocolates to them such that 
If two students sit next to each other, then the one with the higher score must get more chocolates. 
Miss. Noor wants to save money, so she wants to minimize the total number of chocolates.
Input: 4
       1 4 4 6
Output : 6
*/

#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int arr[1000];
	int dp[n];
	int sum = 0;
	cout<<"Enter the elements: ";
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	cout<<"Output is: ";
	dp[0] = 1;
	for(int i = 1; i < n; i++){
		if(arr[i] > arr[i-1]){
			dp[i] = dp[i-1] + 1;
		}
		else{
			dp[i] = 1;
		}
	}
	for(int i = n-2; i >= 0; i--){
		if(arr[i] > arr[i+1] && dp[i] <= dp[i+1]){
			dp[i] = dp[i+1] + 1;
		}
	}
	for(int i = 0; i < n; i++){
		sum = sum + dp[i];
	}
	cout<<sum;
	return 0;
}