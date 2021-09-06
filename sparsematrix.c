//Program to determine whether a given matrix is sparse matrix or not

#include <stdio.h>

int main(){
	int i, j, n, flag=0;
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
			
		}	
	}
	if(flag == 0) printf("Given matrix is an identity matrix.");
	else printf("Given matrix is not an identity matrix.");
	return 0;	
}