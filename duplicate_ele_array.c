//Program to print the duplicate elements of an array

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
	printf("Duplicate elements in given array:\n");
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i]==arr[j]) printf("%d\n",arr[j]);
		}
	}
	return 0;	
}