/* 3 cycle
Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, 
then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) 
are connected by an edge.
Input: 3 3
0 1
1 2
2 0
Output: 1
*/

#include <iostream>
#include <vector>
using namespace std;

int getCycle(int** edges, int n){
	int count = 0;
	for(int i = 0; i < n - 2; i++){
		for(int j = i + 1; j < n - 1; j++){
			for(int k = j + 1; k < n; k++){
				if(edges[i][j] == 1 && edges[j][k] == 1 && edges[k][i] == 1)
					count++;
			}
		}
	}
	return count;
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
	cout<<getCycle(edges, n);
	return 0;
}