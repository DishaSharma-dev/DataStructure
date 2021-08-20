//Program to implement Quick sort

#include <iostream>
using namespace std;

void swap(int*a , int*b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int a[], int l, int r){
	int pivot=a[r];
	int pindex=l;
	for(int i=l;i<r;i++){
		if(a[i]<=pivot){
			swap(a[i],a[pindex]);
			pindex++;
	   }
	}
    swap(a[pindex],a[r]);
	return pindex;	
}

void quick_sort(int a [], int l, int r){
	if(l<r){
		int pindex=partition(a,l,r);
		quick_sort(a,l,pindex-1);
		quick_sort(a,pindex+1,r);
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
quick_sort(arr,0,n-1);
display(arr,n);	
}