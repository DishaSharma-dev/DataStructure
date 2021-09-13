//Merge two sorted array

#include <iostream>
using namespace std;

void merge(int arr1[],int n1, int arr2[],int n2, int output[]){
	int i=0,j=0,k=0;
	while(i<n1 && j<n2){
		if(arr1[i]<arr2[j]){
			output[k]=arr1[i];
			i++;
			k++;
		}
		else{
			output[k]=arr2[j];
			j++;
			k++;	
		}
	}
	while(i<n1){
		output[k]=arr1[i];
		i++;
		k++;
	}
	while(j<n2){
		output[k]=arr2[j];
		j++;
		k++;
	}
}

int main(){
	int n1,n2;
	cout<<"Enter the size of an array1: ";
	cin>>n1;
	int arr1[1000];
	int arr2[1000];
	int output[2000];
	cout<<"Enter the elements in array1: ";
	for(int i=0;i<n1;i++){
		cin>>arr1[i];
	}
	cout<<"Enter the size of an array2: ";
	cin>>n2;
	cout<<"Enter the elements in array2: ";
	for(int i=0;i<n2;i++){
		cin>>arr2[i];
	}
	merge(arr1,n1,arr2,n2,output);
	cout<<"Array after Merging is: ";
	for(int i=0;i<(n1+n2);i++){
		cout<<output[i]<<" ";
	}
}