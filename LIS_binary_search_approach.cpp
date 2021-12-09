/* Longest Increaing Subsequence(LIS) - [nlogn approach]
Given an array with N elements, you need to find the length of the longest subsequence in the given array
such that all elements of the subsequence are sorted in strictly increasing order.
Input: 5 4 11 1 16 8
Output: 3
*/

#include <iostream>
#include <vector>
using namespace std;

int binary_search(int l, int h , vector<int> output, int n){
	while(l < h){
		int mid = (l+h)/2;
		if(output[mid] >= n){
			h = mid;
		}
		else{
			l = mid + 1;
		}
	}
	if(l < output.size() && output[l] < n){
		l++;
	}
	return l;
}

int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int arr[n];
	vector<int> output;
	cout<<"Enter the elements in an array: ";
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	cout<<"Length of longest Increasing Subsequence is: ";
	output.push_back(arr[0]);
	for(int i = 1; i < n; i++){
		if(output.back() < arr[i]){
			output.push_back(arr[i]);
		}
		else{
			int index = binary_search(0 , output.size() - 1, output, arr[i]);
			output[index] = arr[i];
		}
	}
	cout<<output.size();
	return 0;
}
 
