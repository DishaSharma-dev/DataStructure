//Sort 0 1 2 in an array

#include <iostream>
using namespace std;

void swap(int &a , int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int arr[100];
	cout<<"Enter the elements: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int i = 0;
	int j = 0;
	int k = n-1;
	while(i <= k){
		if(arr[i] == 0){
			swap(arr[i],arr[j]);
			i++;
			j++;
		}
		else if(arr[i] == 1) i++;
		else{
			swap(arr[i],arr[k]);
			k--;
		}	
	}
	cout<<"Array is: ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}