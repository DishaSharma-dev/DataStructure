//Program to determine whether given two matrix are equal or not

#include <stdio.h>

int main(){
	int i, j, n, flag=0;
	printf("Enter the size of matrix: ");
	scanf("%d",&n);
	int arr1[n][n];
	printf("Enter the elements in matrix1: ");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d", &arr1[i][j]);
		}	
	}
	int arr2[n][n];
	printf("Enter the elements in matrix2: ");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d", &arr2[i][j]);
		}	
	}
	printf("Matrix1 is:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ", arr1[i][j]);
		}
		printf("\n");	
	}
	printf("Matrix2 is:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ", arr2[i][j]);
		}
		printf("\n");	
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(arr1[i][j] != arr2[i][j]){
				flag=1;
				break;	
			}	
		}	
	}
	if(flag == 0) printf("Given matrix are equal.");
	else printf("Given matrix are not equal.");
	return 0;	
}