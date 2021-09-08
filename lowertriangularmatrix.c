//Program to display lower triangular matrix

#include <stdio.h>

int main(){
	int i, j, n;
	printf("Enter the size of matrix: ");
	scanf("%d",&n);
	int arr[n][n];
	printf("Enter the elements in matrix: ");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d", &arr[i][j]);
		}	
	}
	printf("Original matrix:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");	
	}
	printf("Lower triangular matrix:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i<j)
			printf("0 ");
			else
			printf("%d ", arr[i][j]);
		}
		printf("\n");	
	}
	return 0;	
}