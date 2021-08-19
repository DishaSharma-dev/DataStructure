//Program to implement Selection sort

#include <iostream>
using namespace std;

void selection_sort(int a [], int n){
	int i,j,temp,min;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<=n-1;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
	temp=a[i];
	a[i]=a[min];
	a[min]=temp;
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
selection_sort(arr, n);
display(arr,n);	
}