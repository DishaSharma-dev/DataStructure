//Program to right rotate an array

#include <stdio.h>

void reverse(int arr[], int low, int high){
	while(low < high){
		int temp = arr[low];
		arr[low] = arr[high];
		arr[high] = temp;
		low++;
		high--;
	}
}

int main(){
	int i, j, n ,k;
	printf("Enter the size of an array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements in an array: ");
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);	
	}
	printf("Number of times to right rotate an array: ");
	scanf("%d",&k);
	printf("Original array: ");
	for(i=0;i<n;i++){
		printf("%d ", arr[i]);	
	}
	k=k%n;
	reverse(arr,0,n-k-1);
	reverse(arr,n-k,n-1);
	reverse(arr,0,n-1);
	printf("\nArray after rotation: ");
	for(i=0;i<n;i++){
		printf("%d ", arr[i]);	
	}
	return 0;	
}