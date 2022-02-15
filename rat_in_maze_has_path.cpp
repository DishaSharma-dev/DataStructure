/* Rat in maze(Has path problem)*/

#include <iostream>
using namespace std;

bool hasPathHelper(int** arr, int** sol, int n, int x, int y){
	if(x == n-1 && y == n-1){
		return true;
	}
	if(x < 0 || y < 0 || x >= n || y >= n || arr[x][y] == 0 || sol[x][y] == 1){
		return false;
	}
	sol[x][y] = 1;
	if(hasPathHelper(arr, sol, n, x-1, y)){
		return true;
	}
	if(hasPathHelper(arr, sol, n, x+1, y)){
		return true;
	}
	if(hasPathHelper(arr, sol, n, x, y-1)){
		return true;
	}
	if(hasPathHelper(arr, sol, n, x, y+1)){
		return true;
	}
	sol[x][y] = 0;
	return false;
}

bool hasPath(int** arr, int n){
	int** sol = new int*[n];
	for(int i = 0; i < n; i++){
		sol[i] = new int[n];
		for(int j = 0; j < n; j++){
			sol[i][j] = 0;
		}
	}	
	return hasPathHelper(arr, sol, n, 0, 0);
}

int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int** arr = new int*[n];
	for(int i = 0; i < n; i++){
		arr[i] = new int[n];
		for(int j = 0; j < n; j++){
			cin>>arr[i][j];
		}
	}
	cout<<hasPath(arr, n);
	return 0;
}