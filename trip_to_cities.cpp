/* Trip to Cities
You want to plan a trip to a country with N cities and M bidirectional roads.
But there is a special city called capital C, where you will land. But there is a restriction, 
you can only visit cities which are at most k distance from the capital. 
Can you count the number of cities that you can visit during your trip (including capital) ?
Input: 4 3 1 1
1 2 1
2 3 1
3 4 1
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;


int minDistance(int* distance, bool* visited, int n){
	int minVertex = -1;
	for(int i = 1; i <= n; i++){
		if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}

void dijkstras(int** edges, int n, int k){
	int* distance = new int[n];
	bool* visited = new bool[n];
	for(int i = 1; i <= n; i++){
		distance[i] = INT_MAX;
		visited[i] = false;
	}
	distance[1] = 0;
	for(int i = 1; i <= n; i++){
		int minVertex = minDistance(distance, visited, n);
		visited[minVertex] = true;
		for(int j = 1; j <= n; j++){
			if(edges[j][minVertex] != 0 && !visited[j]){
				if(distance[j] > (edges[j][minVertex] + distance[minVertex])){
					distance[j] = edges[j][minVertex] + distance[minVertex];
				}
			}
		}
	}
	int count = 0;
	for(int i = 1; i <= n; i++){
		if(distance[i] <= k){
			count++;
		}
	}
	cout<<count;
}

int main(){
	int n, e, k;
	cout<<"Enter the number of vertices: ";
	cin>>n;
	cout<<"Enter the number of edges: ";
	cin>>e;
	cout<<"Enter the value of k: ";
	cin>>k;
	int** edges = new int*[n];
	for(int i = 1; i <= n; i++){
		edges[i] = new int[n];
		for(int j = 1; j <= n; j++){
			edges[i][j] = 0;
		}
	}
	for(int i = 1; i <= e; i++){
		int s, d, w;
		cin>>s>>d>>w;
		edges[s][d] = w;
		edges[d][s] = w;
	}
	dijkstras(edges, n, k);
	return 0;
}