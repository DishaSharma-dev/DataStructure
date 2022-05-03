/* Monk and the Island
Monk visits the land of Islands. There are a total of N islands numbered from 1 to N.
Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants
to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the
optimal route.
Input: 2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2
Output: 2
2*/


#include <iostream>
#include <queue>
using namespace std;

void bfs(int** edges, int n){
	int* level = new int[n+1];
	int* visited = new int[n+1];
	for(int i = 1; i <= n; i++){
		visited[i] = false;
	}
	queue<int> q;
	q.push(1);
	level[1] = 0;
	visited[1] = true;
	while(!q.empty()){
		int p = q.front();
		q.pop();
		for(int j = 1; j <= n; j++){
			if(edges[p][j] == 1 && !visited[j]){
				level[j] = level[p] + 1;
				q.push(j);
				visited[j] = true;
			}
		}
	}
	cout<<level[n];
}

int main(){
	int t;
	cout<<"Enter the number of test cases: ";
	cin>>t;
	int n, e;
	for(int i = 0; i < t; i++){
		cout<<"Enter the number of vertices and edges: ";
		cin>>n>>e;
		int** edges = new int*[n+1];
		for(int i = 0; i <= n; i++){
			edges[i] = new int[n+1];
			for(int j = 0; j <= n; j++){
				edges[i][j] = 0;
			}
		}
		for(int i = 0; i < e; i++){
			int x, y;
			cout<<"Enter the edges: ";
			cin>>x>>y;
			edges[x][y] = 1;
			edges[y][x] = 1;
		}
		bfs(edges, n);
	}
	return 0;
}