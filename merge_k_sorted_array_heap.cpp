/* Merge k sorted arrays
Given k different arrays, which are sorted individually (in ascending order).
You need to merge all the given arrays such that output array should be sorted (in ascending order).
Input: 4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0
Output: 0 1 2 5 6 9 45 78 90 100 234
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArray(vector<vector<int>> &v){
	vector<int> output;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v[i].size(); j++){
			pq.push(v[i][j]);
		}
	}
	while(!pq.empty()){
		output.push_back(pq.top());
		pq.pop();
	}
	return output;
}

int main(){
	vector<vector<int>> v;
	vector<int> output;
	int k, n;
	cout<<"Enter the value of k: ";
	cin>>k;
	for(int i = 0; i < k; i++){
		cout<<"Enter the value of n: ";
		cin>>n;
		for(int j = 0; j < n; j++){
			int val;
			cin>>val;
			output.push_back(val);
		}
		v.push_back(output);
		output.clear();
	}
	vector<int> ans = mergeKSortedArray(v);
	for(int i = 0; i < ans.size(); i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
