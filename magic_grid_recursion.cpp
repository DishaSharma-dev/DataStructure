/* Magic Grid TC: 2^(m*n) calls
You are given a magic grid A with R rows and C columns. In the cells of the grid, you will either get magic
juice,which increases your strength by |A[i][j]| points, or poison, which takes away
A[i][j]| strength points.
If at any point of the journey, the strength points become less than or equal to zero, then you will die.
Input: 3 4
       0 -2 -3 1
       -1 4 0 -2
       1 -2 -3 0
Output: 2*/

#include <iostream>
using namespace std;

int magicGrid(int** arr, int n, int m, int h, int need, int i = 0, int j = 0){
	h += arr[i][j];
	need = min(h, need);
	if(i == n-1 && j == m-1){
		return need >= 0 ? 1 : 1 - need;
	}
	if(i == n-1){
		return magicGrid(arr, n, m, h, need, i, j+1);
	}
	if(j == m-1){
		return magicGrid(arr, n, m, h, need, i+1, j);
	}
	return min(magicGrid(arr, n, m, h, need, i+1, j), magicGrid(arr, n, m, h, need, i, j+1));
}

int main(){
	int n,m;
	cout<<"Enter the number of rows: ";
	cin>>n;
	cout<<"Enter the number of columns: ";
	cin>>m;
	int h = 0;
	int** arr = new int*[n];
	for(int i = 0; i < n; i++){
		arr[i] = new int[m];
		for(int j = 0; j < m; j++){
			cin>>arr[i][j];
		}
	}
	cout<<"Output is: ";
	cout<<magicGrid(arr, n, m, h, 0);
	return 0;
}