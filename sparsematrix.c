//Program to determine whether a given matrix is sparse matrix or not

#include <stdio.h>

int main(){
	int i, j, n, count=0;
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
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(arr[i][j] == 0) ++count;	
		}	
	}
	if(count > (n*n)/2) printf("Given matrix is a sparse matrix.");
	else printf("Given matrix is not a sparse matrix.");
	return 0;	
}