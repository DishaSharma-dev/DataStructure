//Pushes zero to the end

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
	int k = n-1;
	for(i = 0;i<n;i++){
		if(arr[i] == 0){
			swap(arr[i],arr[k]);
			i++;
			k--;
		}	
	}
	cout<<"Array is: ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}