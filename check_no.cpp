/* Check number
Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
Do this recursively.
Input: 3
       9 8 10
       8
Output: true
*/
#include <iostream>
using namespace std;

bool check(int arr[], int size, int x){
	if(size == 0){
		return false;
	}
	if(arr[0] == x)
		return true;
	else{
		return check(arr+1,size-1,x);
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
	int output = check(arr,n,x);
	(output == 1) ? cout<<"true" : cout<<"false";
	return 0;
}
