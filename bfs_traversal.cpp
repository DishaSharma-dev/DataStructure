/* BFS Traversal
Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Input: 4 4
0 1
0 3
1 2
2 3
Output: 0 1 3 2*/

#include <iostream>
#include <queue>
using namespace std;

void BFS(int** edges, int n, int sv){
	queue<int> pendingVertices;
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	pendingVertices.push(sv);
	visited[sv] = true;
	while(!pendingVertices.empty()){
		int currentVertex = pendingVertices.front();
		cout<<currentVertex<<" ";
		pendingVertices.pop();
		for(int i = 0; i < n; i++){
			if(i == sv) continue;
			if(edges[currentVertex][i] == 1 && !visited[i]){
				pendingVertices.push(i);
				visited[i] = true;
			}
				
		}
	}
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
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	BFS(edges, n, 0);
	return 0;
}