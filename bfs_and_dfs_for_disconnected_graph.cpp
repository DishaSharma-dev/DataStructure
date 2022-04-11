/* BFS and DFS for disconnected graph */

#include <iostream>
#include <queue>
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

void BFS(int** edges, int n, int sv, bool* &visited){
	queue<int> pendingVertices;
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

void printDFS(int** edges, int n){
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	for(int i = 0; i < n; i++){
		if(!visited[i])
			DFS(edges, n, i, visited);
	}
	delete []visited;
}

void printBFS(int** edges, int n){
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	for(int i = 0; i < n; i++){
		if(!visited[i])
			BFS(edges, n, i, visited);
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
	cout<<"DFS is:\n";
	printDFS(edges, n);
	cout<<"BFS is: \n";
	printBFS(edges, n);
	return 0;
}
