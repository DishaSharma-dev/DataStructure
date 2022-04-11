/* Get Path - DFS
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers),
find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
Input: 4 4
0 1
0 3
1 2
2 3
1 3
Output: 3 0 1
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> getPath(int** edges,int n,int start,int end,bool *visited){
  visited[start]=true;
  if(start==end){
    vector <int> temp;
    temp.push_back(start);
    return temp;
  }  
  vector <int> ans;
  for(int i=0;i<n;i++){
    if(i==start)
      continue;
    if(edges[start][i] && !visited[i]){
      ans=getPath(edges,n,i,end,visited);
      if(!ans.empty()){
        ans.push_back(start);
        return ans;
      }
    }
  }
  return ans;
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
	vector<int> output = getPath(edges, n, s, end, visited);
	for(int i = 0; i < output.size(); i++){
		cout<<output[i]<<" ";
	}
	return 0;
}