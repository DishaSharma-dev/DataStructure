/* Matrix Chain Multiplication (Recursive Approach) 
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices.
In other words, determine where to place parentheses to minimize the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i].
You need to find minimum number of multiplications needed to multiply the chain.

Input: 3
       10 15 20 25
Output: 8000
Explanation: There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.
If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000. */

#include <iostream>
using namespace std;

int mcm(int* arr, int start, int end){
	if(start == end){
		return 0;
	}
	int k;
	int min = INT_MAX;
	int count;
	for(k = start; k < end; k++){
		count = mcm(arr, start, k) + mcm(arr, k+1, end) + (arr[start - 1] * arr[k] * arr[end]);
		if(count < min){
			min = count;
		}
	}
	return min;
}

int main(){
	int n;
	cout<<"Enter the value of n: ";
	cin>>n;
	int arr[n+1];
	cout<<"Enter the values in an array: ";
	for(int i = 0; i <= n; i++){
		cin>>arr[i];
	}
	cout<<"Output is: ";
	cout<<mcm(arr, 1, n);
	return 0;
} 