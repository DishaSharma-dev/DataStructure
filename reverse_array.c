//Program to print the elements of an array in reverse order

#include <stdio.h>

int main(){
	int i, j, n;
	printf("Enter the size of an array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements in an array: ");
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);	
	}
	printf("Array in reverse order:\n");
	for(i=n-1;i>=0;i--){
		printf("%d ",arr[i]);
	}
	return 0;	
}