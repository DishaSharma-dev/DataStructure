/* In-place Heap Sort
Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
Note: Space complexity should be O(1).
Input: 6 
	   2 6 8 5 4 3
Output: 8 6 5 4 3 2
*/

#include <iostream>
#include <vector>
using namespace std;

void heapSort(int* &arr, int n){
	for(int i = 1; i < n; i++){
		int childIndex = i;
		while(childIndex > 0){
			int parentIndex = (childIndex - 1)/2;
			if(arr[parentIndex] > arr[childIndex]){
				int temp = arr[parentIndex];
				arr[parentIndex] = arr[childIndex];
				arr[childIndex] = temp;
			}
			else{
				break;
			}
			childIndex = parentIndex;
		}
	}
	int size = n;
	while(size > 1){
		int temp = arr[0];
		arr[0] = arr[size - 1];
		arr[size - 1] = temp;
		size--;
		int parentIndex = 0;
		int leftChild = 2 * parentIndex + 1;
		int rightChild = 2 * parentIndex + 2;
		while(leftChild < size){
			int minIndex = parentIndex;
			if(arr[leftChild] < arr[minIndex]){
				minIndex = leftChild;
			}
			if(rightChild < size && arr[rightChild] < arr[minIndex]){
				minIndex = rightChild;
			}
			if(minIndex == parentIndex) break;
			int temp = arr[minIndex];
			arr[minIndex] = arr[parentIndex];
			arr[parentIndex] = temp;
			parentIndex = minIndex;
			leftChild = 2 * parentIndex + 1;
			rightChild = 2 * parentIndex + 2;
		}
	}
}

int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	cout<<"Enter the elements in an array: ";
	int* arr = new int[n];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	heapSort(arr, n);
	cout<<"Output is: ";
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}