//Program to print the kth smallest number of an array

#include <stdio.h>

int main(){
	int i, j, n,k;
	printf("Enter the size of an array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements in an array: ");
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);	
	}
	printf("Enter the value of k: ");
	scanf("%d", &k);
	printf("Original Array: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);	
	}
	for(i=1;i<=n-1;i++){
		int temp = arr[i];
		j=i-1;
		while(j>=0 && arr[j]>temp){
			arr[j+1] = arr[j];
			j = j-1;
		}
	arr[j+1] = temp;
	}
	printf("\nkth smallest number: ");
	printf("%d",arr[k-1]);
	return 0;	
}