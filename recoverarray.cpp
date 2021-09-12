//Sepearte mid from array and recover original array
//3 2 4 1 5 => 1 2 3 4 5

#include <iostream>
using namespace std;


void recover_array(int arr[],int n,int output[]){
	int left,right;
	int i=0;
	int mid=n/2;
	if(n%2 !=0){
		output[mid]=arr[0];
		left=mid-1;
		right=mid+1;
		i++;
	}
	else{
		left=mid-1;
		right=mid;
	}
	while(i<n){
		output[left]=arr[i];
		left--;
		i++;
		output[right]=arr[i];
		right++;
		i++;
	}
}
int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int arr[1000];
	int output[1000];
	cout<<"Enter the elements: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	recover_array(arr,n,output);
	cout<<"Original array is: ";
	for(int i=0;i<n;i++){
		cout<<output[i]<<" ";
	}
}