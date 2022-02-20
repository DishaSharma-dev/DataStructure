/* Sudoku Solver */
#include <iostream>
using namespace std;

bool isValid(int** &matrix, int row, int col, int z){
	for(int i = 0; i < 9; i++){
		if(matrix[row][i] == z)
			return false;
		if(matrix[i][col] == z)
			return false;
		if(matrix[3 *(row/3) + i/3][3 * (col/3) + i % 3] == z)
			return false;
	}
	return true;
}

bool solve(int** &matrix){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(matrix[i][j] == 0){
				for(int z = 1; z <= 9; z++){
					if(isValid(matrix, i, j, z)){
						matrix[i][j] = z;
						if(solve(matrix) == true){
							return true;
						}
						else{
							matrix[i][j] = 0;
						}	
					}
				}
				return false;
			}	
		}
	}
	return true;
}

int main(){
	int**  matrix = new int* [9];
	for(int i = 0; i < 9; i++){
		matrix[i] = new int[9];
		for(int j = 0; j < 9; j++){
			cin>>matrix[i][j];
		}
	}
	cout<<solve(matrix);
	return 0;
}