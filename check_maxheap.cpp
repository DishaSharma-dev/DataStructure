/* Check max Heap
Input: Given an array of integers, check whether it represents max-heap or not.
Return true if the given array represents max-heap, else return false.
Input: 8
	   42 20 18 6 14 11 9 4
Output: true
*/

#include <iostream>
using namespace std;

bool checkMaxHeap(int* arr, int n){
	for(int i = 0; (2 * i + 1) < n; i++){
		int leftIndex = 2 * i + 1;
		int rightIndex = leftIndex + 1;
		if(arr[i] < arr[leftIndex]) return false;
		if(rightIndex < n && arr[i] < arr[rightIndex]) return false;
	}
	return true;
}

int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int* arr = new int[n];
	cout<<"Enter the elements: ";
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	int output = checkMaxHeap(arr, n);
	(output == 0) ? cout<<"false" : cout<<"true";
	return 0;
}