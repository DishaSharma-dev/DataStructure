/* Count ways
There exists a special graph which has directed M edges and N nodes and graph contains no cycles. 
Count the number of ways to reach different nodes from S. A way is called different from others
if the destination node or used edges differ. As the ways can be large, print the ways modulo 1000000007.
Include source node as destination also.
Input: 4 3
1 2
2 3
3 4
2
Output: 3*/

#include <iostream>
using namespace std;

int countWays(int src, int** edges, int n){
	int count = 1;
	for(int i = 1; i <= n; i++){
		if(edges[src][i] == 1){
			count += (countWays(i, edges, n)) % 1000000007;
		}
	}
	return count;
}

int main(){
	int n, e, src;
	cout<<"Enter the vertices: ";
	cin>>n;
	cout<<"Enter the edges: ";
	cin>>e;
	int** edges = new int*[n];
	for(int i = 1; i <= n; i++){
		edges[i] = new int[n];
		for(int j = 1; j <= n; j++){
			edges[i][j] = 0;
		}
	}
	for(int i = 1; i <= e; i++){
		int s, d;
		cin>>s>>d;
		edges[s][d] = 1;
	}
	cout<<"Enter source: ";
	cin>>src;
	int output = countWays(src, edges, n);
	cout<<output;
	return 0;
}
