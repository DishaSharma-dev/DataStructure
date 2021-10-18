/* Longest Subset
Given an array, find and return the length of longest subarray containing equal number of 0s and 1s.
Input : 6 
        1 0 0 1 1 1
Output: 4
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int n;
	int arr[1000];
	unordered_map<int,int> m;
	int sum = 0;
	int longest_subset;
	cout<<"Enter the size of an array: ";
	cin>>n;
	cout<<"Enter the elements: ";
	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	for(int  i = 0; i < n; i++) {
		sum += arr[i] == 0 ? -1 : 1;
		if(sum == 0){
			if(longest_subset < (i+1))
				longest_subset = i+1;
		}
		else if(m.find(sum) != m.end()){
			if(longest_subset < (i-m[sum]))
				longest_subset = i-m[sum];
		}
		else {
			m[sum] = i;
		}
	}
	cout<<longest_subset;
	return 0;
}