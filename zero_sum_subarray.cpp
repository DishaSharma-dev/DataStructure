/* Zero Sum Subarray
Write a program to return true if there exists a sub-array whose sum is zero else, return false.
Input 1 => 6 
7 1 3 -4 5 1
Output => true
========================================
Input 2 => 5 
-6 7 6 2 1
Output => false
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int arr[1000];
	int ans = 0;
	int sum = 0;
	unordered_map<int ,int> map;
	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	for(int i = 0; i < n; i++){
		sum = sum + arr[i];
		if(map.find(sum) != map.end()) {
			ans = ans + map[sum];
		}
		map[sum]++;
	}
	ans > 0 ? cout<<"true" : cout<<"false";
	return 0;
}