/* Has Path
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers),
check if there exists any path between them or not. Print true if the path exists and false otherwise.
Input: 4 4
0 1
0 3
1 2
2 3
1 3
Output: true*/

#include <iostream>
using namespace std;

bool hasPath(int** edges, int n, int s, int e, bool* visited){
	if(s == e) return true;
	visited[s] = true;
	for(int i = 0; i < n; i++){
		if(!visited[i] && edges[s][i] == 1){
			if(hasPath(edges, n, i, e, visited)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int n, e;//no of vertices and edges
	cin>>n;
	cin>>e;
	int s, end;
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
	cout<<"Enter start vertex: ";
	cin>>s;
	cout<<"Enter end vertex: ";
	cin>>end;
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	int output = hasPath(edges, n, s, end, visited);
	output == 1 ? cout<<"true" : cout<<"false";
	return 0;
}