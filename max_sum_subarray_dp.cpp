/* Maximum Sum Subarray (Dynamic Programming Approach)
Given an integer array containing both negative and positive integers. 
Find and return the sum of contiguous sub-array with maximum sum.
Input: 4
       -1 -2 -3 -4
Output: -1*/

#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of an array: ";
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	cout<<"Maximum Sum of the subarray is: ";
	int max_ending_here = 0;
	int best = arr[0];
	for(int i = 0; i < n; i++){
		max_ending_here = max_ending_here + arr[i];
		if(best < max_ending_here){
			best = max_ending_here;
		}
		if(max_ending_here < 0){
			max_ending_here = 0;
		}
	}
	cout<<best;
	return 0;
}