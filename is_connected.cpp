/* Is connected
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
Input: 4 4
0 1
0 3
1 2
2 3
Output: true
*/

#include <iostream>
using namespace std;

void check(int** edges, int n, int sv, bool* &visited){
	visited[sv] = true;
	for(int i = 0; i < n; i++){
		if(i == sv) continue;
		if(edges[sv][i] == 1){
			if(visited[i]) continue;
			check(edges, n, i, visited);
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
	bool done = false;
	check(edges, n, 0, visited);
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			cout<<"false";
			done = true;
		}
	}
	if(!done){
		cout<<"true";
	}
	return 0;
}