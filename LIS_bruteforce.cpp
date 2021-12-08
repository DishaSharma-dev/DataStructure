/* Longest Increaing Subsequence(LIS) - Bruteforce
Given an array with N elements, you need to find the length of the longest subsequence in the given array
such that all elements of the subsequence are sorted in strictly increasing order.
Input: 5 4 11 1 16 8
Output: 3
*/

#include <iostream>
#include <cmath>
using namespace std;

int LIS(int prev, int curr, int arr[], int size){
	if(curr == size){
		return 0;
	}
	int ans1 = 0;
	if(prev < arr[curr]){
		ans1 = 1 + LIS(arr[curr],curr+1,arr,size);
	}
	int ans2 = LIS(prev,curr+1,arr,size);
	return max(ans1,ans2);
}


int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements in an array: ";
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	cout<<"Length of longest Increasing Subsequence is: ";
	cout<<LIS(-1,0,arr,n);
	return 0;
}
 
