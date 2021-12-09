/* Longest Increaing Subsequence(LIS) - Dynamic Programming(o n ^ 2)
Given an array with N elements, you need to find the length of the longest subsequence in the given array
such that all elements of the subsequence are sorted in strictly increasing order.
Input: 5 4 11 1 16 8
Output: 3
*/

#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int arr[n];
	int output[n];
	cout<<"Enter the elements in an array: ";
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	cout<<"Length of longest Increasing Subsequence is: ";
	output[0] = 1;
	for(int i = 1; i < n; i++){
		output[i] = 1;
		for(int j = i-1; j >= 0; j--){
			if(arr[i] <= arr[j])
				continue;
			int possibleans = output[j] + 1;
			if(possibleans > output[i]){
				output[i] = possibleans;
			}	
		}
	}
	int max_count = -1;
	for(int i = 0; i < n; i++){
		if(output[i] > max_count){
			max_count = output[i];
		}
	}
	cout<<max_count;
	return 0;
}
 
