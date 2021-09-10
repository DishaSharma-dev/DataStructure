//Identify duplicate element in an array

#include <iostream>
using namespace std;

int main(){
	int n,flag=0;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Original Array is: ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	for(int i=0;i<n-1;i++){
		if(arr[i]>arr[i+1]){
		int temp = arr[i];
		arr[i] = arr[i+1];
		arr[i+1] = temp;
		i = -1;	
		}
	}
	cout<<"\nDuplicate element is: ";
	for(int i=0;i<n-1;i++){
		if(arr[i] == arr[i+1]){
			cout<<arr[i];
			flag=1;
			break;
		}
	}
	if(flag == 0) cout<<"0";
}