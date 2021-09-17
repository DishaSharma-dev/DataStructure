// Program to implement linear search using 2d arrays

#include <stdio.h>

int main(){
	int m,n,i,j,x,flag=0;
	printf("Enter the number of rows in an array: ");
	scanf("%d", &m);
	printf("Enter the number of cols in an array: ");
	scanf("%d", &n);
	int arr[100][100];
	printf("Enter the elements: ");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	printf("Enter the element to search: ");
	scanf("%d", &x);
	for(i = 0; i < m; i++){   //traverse an array to compare the element with all ie present in an array
		for(j = 0; j < n; j++){
			if(arr[i][j] == x){
			printf("Element is found at %d",i+1);
			flag = 1;
			break;
	       }
		}
	}
	if(flag == 0)
		printf("Element not found");
	return 0;
}