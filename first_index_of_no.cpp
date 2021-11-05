/* First Index of Number
Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array.
Return -1 if it is not present in the array.
Input: 4
       9 8 10 8
       8
Output: 1
*/
#include <iostream>
using namespace std;

int first_index(int arr[], int size, int x){
	if(size == 0){
		return -1;
	}
	if(arr[0] == x)
		return 0;
	int ans = first_index(arr+1,size-1,x);
	if(ans == -1){
		return -1;
	}
	else{
		return ans+1;
	}
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
	cout<<first_index(arr,n,x);
	return 0;
}
