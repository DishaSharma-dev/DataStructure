/* Islands
An island is a small piece of land surrounded by water . A group of islands is said to be connected 
if we can reach from any given island to any other island in the same group .
Given V islands (numbered from 1 to V) and E connections or edges between islands. 
Can you count the number of connected groups of islands.
Input: 5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3
Output: 1
*/

#include <iostream>
using namespace std;

void DFS(int** edges, int n, int sv, bool* &visited){
	visited[sv] = true;
	for(int i = 0; i < n; i++){
		if(i == sv) continue;
		if(edges[sv][i] == 1){
			if(visited[i]) continue;
			DFS(edges, n, i, visited);
		}
	}
}

int printDFS(int** edges, int n){
	bool* visited = new bool[n];
	int count = 0;
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	for(int i = 0; i < n; i++){
		if(!visited[i])
		    count++;
			DFS(edges, n, i, visited);
	}
	delete []visited;
	return count;
}


int main(){
	int n, e;//no of vertices and edges
	cin>>n;
	cin>>e;
	int** edges = new int*[n];
	for(int i = 0; i < n; i++){
		edges[i] = new int[n];
		for(int j = 0; j < n; j++){
			edges[i][j] = 0;
		}
	}
	for(int i = 0; i < e; i++){
		int f,s;
		cin>>f;
		cin>>s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	cout<<printDFS(edges, n);
	return 0;
}
