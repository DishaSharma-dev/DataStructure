/* N Queen Problem
You are given N, and for a given N x N chessboard,
find a way to place N queens such that no queen can attack any other queen on the chess board.
A queen can be killed when it lies in the same row, or same column, or the same diagonal of any 
of the other queens.You have to print all such configurations.
Input: 4
Output: 0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
        0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
*/

#include <iostream>
#define N 8
using namespace std;


bool isSafe(int row, int col, int board[N][N]){
	int duprow = row;
	int dupcol = col;
	while(row >= 0 && col >= 0){
		if(board[row][col] == 1) return false;
		row--;
		col--;
	}
	row = duprow;
	col = dupcol;
	while(col >= 0){
		if(board[row][col] == 1) return false;
		col--;
	}
	row = duprow;
	col = dupcol;
	while(row < N && col >= 0){
		if(board[row][col] == 1) return false;
		row++;
		col--;
	}
	return true;
}

void printBoard(int board[N][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool solve(int col, int board[N][N]){
	if(col >= N){
		return true;
	}
	for(int row = 0; row < N; row++){
		if(isSafe(row, col, board)){
			board[row][col] = 1;
			if(solve(col+1, board)){
				return true;
			}
			board[row][col] = 0;
		}
	}
	return false;
}

void checkSolution(int col, int board[N][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			board[i][j] = 0;
		}
	}
	if(solve(0, board)){
		printBoard(board);
	}
}

int main(){
	int n;
	cout<<"Enter the value of n: ";
	cin>>n;
    int board[N][N];
	checkSolution(0, board);
	return 0;
}

