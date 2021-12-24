/* Number of APs
Given an array of n positive integers. The task is to count the number of Arithmetic Progression subsequences in the array. 
As the answer could be very large, output it modulo 100001.
Note: Empty sequence or single element sequence is Arithmetic Progression.
Input: 3
       1 2 3
Output : 8
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
	int n;
	unordered_map<int,int> * map = new unordered_map<int,int>[n];
	cout<<"Enter the size of an array: ";
	cin>>n;
	int arr[1000];
	int ans = n + 1;
	cout<<"Enter the elements: ";
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	cout<<"Output is: ";
	// For 2 digit AP
	for(int i = 0; i < n-1; i++){
		for(int j = i + 1; j < n; j++){
			int diff = arr[j] - arr[i];
			map[i][diff] += 1;
			ans = (ans + 1) % 100001;
		}
	}
	// More than 2 digit
	for(int i = n - 3; i >= 0; i--){
		for(int j = i + 1; j < n; j++){
			int diff = arr[j] - arr[i];
			map[i][diff] = (map[j][diff] + map[i][diff]) % 100001;
			ans = (ans + map[j][diff]) % 100001;
		}
	}
	cout<<ans;
	return 0;
}