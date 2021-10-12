/* Pair with difference K
You are given with an array of integers and an integer K.
You have to find and print the count of all such pairs which have difference K
Input => 4 
         5 1 2 4
         3
Output => 2
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
	int n,k;
	int pair = 0;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int arr[1000];
	unordered_map<int,int> map;
	cout<<"Enter the elements of an array: ";
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		map[arr[i]]++;
	}
	cout<<"Enter the value of k: ";
	cin>>k;
	for(int i = 0; i < n;i++){
		if(map[arr[i]] > 1){
			int index = arr[i];
			if(map.count(index + k) > 0) {
				map[index]--;
				int freq = map[index + k];
				pair = pair + freq;
			}
		}
		else if(map.count(map.count(arr[i] + k) > 0 )){
			int freq = map[arr[i] + k];
			pair = pair + freq;
		}
	}
	cout<<pair;
	return 0;
}