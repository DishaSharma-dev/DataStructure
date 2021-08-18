//Program to implement Bubble sort

#include <iostream>
using namespace std;

void bubble_sort(int a [], int n){
	int i,j,temp;
	for(i=1;i<=n-1;i++){
		for(j=0;j<=n-i-1;j++){
			temp=a[j];
			if(a[j]>a[j+1]){
			a[j]= a[j+1];
			a[j+1]=temp;	
			}
		}
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
bubble_sort(arr, n);
display(arr,n);	
}