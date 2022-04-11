/* All connected components 
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
Input: 4 2
0 1
2 3
Output: 0 1 
2 3 
*/

#include <iostream>
using namespace std;

void DFS(int** edges, int n, int sv, bool* &visited){
	cout<<sv<<" ";
	visited[sv] = true;
	for(int i = 0; i < n; i++){
		if(i == sv) continue;
		if(edges[sv][i] == 1){
			if(visited[i]) continue;
			DFS(edges, n, i, visited);
		}
	}
}

void printDFS(int** edges, int n){
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	for(int i = 0; i < n; i++){
		if(!visited[i])
			DFS(edges, n, i, visited);
			cout<<endl;
	}
	delete []visited;
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
	printDFS(edges, n);
	return 0;
}
