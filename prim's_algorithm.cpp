/* Prim's Algorithm
Given an undirected, connected and weighted graph G(V, E) with V number of vertices 
(which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
Input: 4 4
0 1 3
0 3 5
1 2 1
2 3 8
Output: 0 1 3
1 2 1
0 3 5
*/

#include <bits/stdc++.h>
using namespace std;

int findMinVertex(int* weight, bool* visited, int n){
	int minVertex = -1;
	for(int i = 0; i < n; i++){
		if(!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}

void prims(int** edges, int n){
	int* weight = new int[n];
	int* parent = new int[n];
	parent[0] = -1;
	weight[0] = 0;
	for(int i = 1; i < n; i++){
		weight[i] = INT_MAX;
	}
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	for(int i = 0; i < n; i++){
		int minVertex = findMinVertex(weight, visited, n);
		visited[minVertex] = true;
		for(int j = 0; j < n; j++){
			if(edges[j][minVertex] != 0 && !visited[j]){
				if(edges[j][minVertex] < weight[j]){
					weight[j] = edges[j][minVertex];
					parent[j] = minVertex;
				}
			}
		}
	}
	for(int j = 1; j < n; j++){
		if(parent[j] < j){
			cout<<parent[j]<<" "<<j<<" "<<weight[j]<<endl;
		}
		else{
			cout<<j<<" "<<parent[j]<<" "<<weight[j]<<endl;
		}
	}
}

int main(){
	int n, e;
	cout<<"Enter the number of vertices: ";
	cin>>n;
	cout<<"Enter the number of edges: ";
	cin>>e;
	int** edges = new int*[n];
	for(int i = 0; i < n; i++){
		edges[i] = new int[n];
		for(int j = 0; j < n; j++){
			edges[i][j] = 0;
		}
	}
	for(int i = 0; i < n; i++){
		int s, d, w;
		cin>>s>>d>>w;
		edges[s][d] = w;
		edges[d][s] = w;
	}
	prims(edges, n);
	return 0;
}