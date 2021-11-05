/* All Indices of Number
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array.
Save all the indexes in an array (in increasing order).
Input: 5
       9 8 10 8 8
       8
Output: 1 3 4
*/
#include <iostream>
using namespace std;

int all_indices(int arr[], int size, int x , int output[]){
	if(size == 0){
		return 0;
	}
	int ans = all_indices(arr,size-1,x,output);
	if(x == arr[size-1]){
		output[ans] = size-1;
		return ans + 1;
	}
	return ans;
}

int main(){
	int n;
	int arr[100];
	int x;
	cout<<"Enter the size of an array: ";
	cin>>n;
	cout<<"Enter the elements in an array: ";
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	cout<<"Enter the number to search: ";
	cin>>x;
	int output[100];
	int size = all_indices(arr,n,x,output);
	for(int i = 0; i < size; i++){
		cout<<output[i]<<" ";
	}
	return 0;
}
