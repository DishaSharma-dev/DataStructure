// Program to implement linear search using arrays

#include <stdio.h>

int main(){
	int n,i,x,flag=0;
	printf("Enter the size of an array: ");
	scanf("%d", &n);
	int arr[100];
	printf("Enter the elements: ");
	for(i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	printf("Enter the element to search: ");
	scanf("%d", &x);
	for(i = 0; i < n; i++){   //traverse an array to compare the element with all ie present in an array
		if(arr[i] == x){
			printf("Element is found at %d",i+1);
			flag = 1;
			break;
	    }
	}
	if(flag == 0)
		printf("Element not found");
	return 0;
}