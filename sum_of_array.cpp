/* Sum of array
Given an array of length N, you need to find and return the sum of all elements of the array.
Do this recursively.
Input: 3
       9 8 9
Output: 26
*/
#include <iostream>
using namespace std;

int sum(int arr[], int size){
	if(size == 0)
		return 0;
	else{
		return arr[0] + sum(arr+1,size-1);
    }
}

int main(){
	int n;
	int arr[100];
	cout<<"Enter the size of an array: ";
	cin>>n;
	cout<<"Enter the elements in an array: ";
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	cout<<"Sum of array is: ";
	cout<<sum(arr,n);
	return 0;
}
