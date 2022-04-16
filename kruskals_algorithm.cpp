/* Kruskal's Algorithm
Given an undirected, connected and weighted graph G(V, E) with V number of vertices 
(which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
Input: 4 4
0 1 3
0 3 5
1 2 1
2 3 8
Output: 1 2 1
0 1 3
0 3 5
*/

#include <bits/stdc++.h>
using namespace std;

class Edge{
	public:
		int source;
		int destination;
		int weight;
};

bool compare(Edge e1, Edge e2){
	return e1.weight < e2.weight;
}

int findParent(int v, int* parent){
	if(v == parent[v]){
		return v;
	}
	return findParent(parent[v], parent);
}

void kruskals(Edge* input, int n, int e){
	sort(input, input + e, compare);
	int* parent = new int[n];
	for(int i = 0; i < n; i++){
		parent[i] = i;
	}
	Edge* output = new Edge[n-1];
	int count = 0;
	int i = 0;
	while(count != n-1){
		Edge currentEdge = input[i];
		int sourceParent = findParent(currentEdge.source, parent);
		int destinationParent = findParent(currentEdge.destination, parent);
		if(sourceParent != destinationParent){
			output[count]= currentEdge;
			count++;
			parent[sourceParent] = destinationParent;
		}
		i++;
	}
	for(int i = 0; i < n-1; i++){
		if(output[i].source < output[i].destination){
			cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
		}
		else{
			cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
		}
	}
}

int main(){
	int n, e;
	cout<<"Enter the number of vertices: ";
	cin>>n;
	cout<<"Enter the number of edges: ";
	cin>>e;
	Edge* input = new Edge[e];
	int s, d, w;
	for(int i = 0; i < e; i++){
		cin>>s;
		cin>>d;
		cin>>w;
		input[i].source = s;
		input[i].destination = d;
		input[i].weight = w;
	}
	kruskals(input, n, e);
	return 0;
}