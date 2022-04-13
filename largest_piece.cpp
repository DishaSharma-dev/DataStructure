/*Largest Piece
It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's .
But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which
consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N 
and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?
Input: 2
1 1
0 1
Output: 3
*/

#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>> &cake, vector<vector<bool>> &used, int n, int x, int y){
	used[x][y] = true;
	int count = 1;
	int dxdy[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	for(int i = 0; i < 4; i++){
		int newX = x + dxdy[i][0];
		int newY = y + dxdy[i][1];
		if(newX < n && newY < n && newX >= 0 && newY >= 0 && !used[newX][newY] && cake[newX][newY] == 1){
			count += dfs(cake, used, n, newX, newY);
		}
	}
	return count;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n){
	vector<vector<bool>> used(n, vector<bool>(n, false));
	int maxi  = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(cake[i][j] == 1 && !used[i][j]){
				maxi = max(maxi, dfs(cake, used, n, i, j));
			}
		}
	}
	return maxi;
}

int main(){
	int n;
	cout<<"Enter the value of n: ";
	cin>>n;
	vector<vector<int>> cake;
	cout<<"Enter the value: ";
	for(int i = 0; i < n; i++){
		vector<int> c;
		for(int j = 0; j < n; j++){
			int ch;
			cin>>ch;
			c.push_back(ch);
		}
		cake.push_back(c);
	}
	cout<<getBiggestPieceSize(cake, n);
	return 0;
}

