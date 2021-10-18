/* Nearest Repetation
Given an integer array, find and return the minimum distance between indexes of an element and its repetition.
Input : 6 
        1 3 1 5 4 3
Output: 2
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int n;
	int arr[1000];
	unordered_map<int,int> map;
	int nearest_distance = 0;
	int min = n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	cout<<"Enter the elements: ";
	for(int i = 0; i < n; i++) {
		cin>>arr[i];
		map[arr[i]] = i;
	}
	for(int i = 0; i < n; i++) {
		if(map[arr[i]] != i) {
			nearest_distance = map[arr[i]] - i;
			if(nearest_distance < min){
				min = nearest_distance;
			}
		}
	}
	cout<<min;
	return 0;
}