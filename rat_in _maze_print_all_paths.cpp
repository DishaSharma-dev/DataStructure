/* Rat in maze(Has path problem)*/

#include <iostream>
using namespace std;

void printPathHelper(int** arr, int** sol, int n, int x, int y){
	if(x == n-1 && y == n-1){
		sol[x][y] = 1;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}
	if(x < 0 || y < 0 || x >= n || y >= n || arr[x][y] == 0 || sol[x][y] == 1){
		return;
	}
	sol[x][y] = 1;
	printPathHelper(arr, sol, n, x-1, y);
	printPathHelper(arr, sol, n, x+1, y);
    printPathHelper(arr, sol, n, x, y-1);
    printPathHelper(arr, sol, n, x, y+1);
	sol[x][y] = 0;
}


bool hasPath(int** arr, int n){
	int** sol = new int*[n];
	for(int i = 0; i < n; i++){
		sol[i] = new int[n];
		for(int j = 0; j < n; j++){
			sol[i][j] = 0;
		}
	}	
	printPathHelper(arr, sol, n, 0, 0);
	return true;
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
	hasPath(arr, n);
	return 0;
}