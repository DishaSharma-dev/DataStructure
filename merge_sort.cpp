//Program to implement Merge sort

#include <iostream>
using namespace std;


void merge(int a[], int l, int m, int r){
	int n1= m-l+1;
	int n2= r-m;
	int left[n1];
	int right[n2];
	for(int i=0;i<n1;i++)
		left[i]=a[l+i];
	for(int j=0;j<n2;j++)
		right[j]=a[m+1+j];
	int i=0;
	int j=0;
	int k=p;
	while(i<n1 && j<n2){
		if(left[i]<=right[j]){
			a[k]=left[i];
			i++;
		}
		else{
			a[k]=right[j];
			j++;
		}
	k++;
	}
	while(i<n1){
		a[k]=left[i];
		k++;
		i++;	
	}
	while(j<n2){
		a[k]=right[j];
		k++;
		j++;	
	}
}

void merge_sort(int a [], int l, int r){
	if(l<r){
		int m=(l+r)/2;
		merge_sort(a,l,m);
		merge_sort(a,m+1,r);
		merge(a,l,m,r);
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
merge_sort(arr,0,n-1);
display(arr,n);	
}