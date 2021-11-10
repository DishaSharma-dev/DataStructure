//Program to implement Merge sort

#include <iostream>
using namespace std;


void merge(int input[],int i1,int j1,int i2,int j2)
{int temp[1000];    
    int i,j,k;
    i=i1;    
    j=i2;    
    k=0;
    
    while(i<=j1 && j<=j2)    
    {
        if(input[i]<input[j])
            temp[k++]=input[i++];
        else
            temp[k++]=input[j++];
    }
    
    while(i<=j1)   
        temp[k++]=input[i++];
        
    while(j<=j2)    
        temp[k++]=input[j++];
        
   
    for(i=i1,j=0;i<=j2;i++,j++)
        input[i]=temp[j];


}

void merge_sort(int a [], int l, int r){
	if(l<r){
		int m=(l+r)/2;
		merge_sort(a,l,m);
		merge_sort(a,m+1,r);
		merge(a,l,m,m+1,r);
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