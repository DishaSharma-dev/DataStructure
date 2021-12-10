/* Maximum Sum Subarray (Brute Force Approach)
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
	int max = INT_MIN;
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = 0; j < n; j++){
			sum += arr[j];
			if(sum > max){
				max = sum;
			}
		}
	}
	cout<<max;
	return 0;
}