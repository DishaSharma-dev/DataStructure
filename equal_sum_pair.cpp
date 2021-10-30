/* Equal Sum Pair
Given an integer array of size N, determine whether 4 elements exist such that a+b = c+d. Return true or false accordingly.
Perform this in O(n^2).
Input: 6
       9 8 7 10 20 30 
Output: true
Explanation: 9+8 = 10+7
*/
#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
	int n;
	int sum = 0;
	int arr[100];
	int flag = 1;
	cout<<"Enter the size of an array: ";
	cin>>n;
	cout<<"Enter the elements in an array: ";
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	unordered_map<int,bool> map;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			sum = arr[i] + arr[j];
			if(map.find(sum) != map.end()){
				flag = 0;
			}
			else{
				map[sum] = true;
			}
		}
	}
	if(flag == 1){
		cout<<"false";
	}
	else{
		cout<<"true";
	}
	return 0;
}