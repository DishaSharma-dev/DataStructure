/* Get Path - BFS
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers),
find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
Input: 4 4
0 1
0 3
1 2
2 3
1 3
Output: 3 0 1
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> getPath(int** edges,int n,int s,int e,bool *visited){
  if(s == e){
    vector <int> temp;
    temp.push_back(s);
    return temp;
  }  
  vector <int> ans;
  queue<int> q;
  q.push(s);
  visited[s] = true;
  bool done = false;
  unordered_map<int, int> map;
  while(!q.empty() && !done){
  	int currentVertex = q.front();
  	q.pop();
  	for(int i = 0; i < n; i++){
  		if(edges[currentVertex][i] == 1 && !visited[i]){
  			map[i] = currentVertex;
			q.push(i);
			visited[i] = true;
			if(i == e){
				done = true;
				break;
			}	
		}	
	}
  }
  if(!done){
  	return ans;
  }
  else{
  	ans.push_back(e);
  	int current = e;
  	while(current != s){
  		current = map[current];
  		ans.push_back(current);
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