//Program to implement insertion sort

//Program to implement insertion sort

#include <iostream>
using namespace std;

void insertion_sort(int a [], int n){
	int i,j,temp;
	for(j=1;j<=n-1;j++){
		temp= a[j];
		i=j-1;
		while(i>=0 && a[i]>temp){
			a[i+1]=a[i];
			i=i-1;
		}
	a[i+1]=temp;
	}
}

void display(int a[], int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}

int main(){
int n;
cout<<"Enter the size of an array: ";
cin>>n;
int arr[n];
cout<<"Enter the elements: ";
for(int i=0;i<n;i++){
	cin>>arr[i];
}
insertion_sort(arr, n);
display(arr,n);	
}