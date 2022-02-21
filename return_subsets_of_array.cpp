/* Return Subsets of an array 
Input: 3
       15, 20, 12
Output: [], 12, 20, 20 12, 15, 15 12, 15 20, 15 20 12
*/

#include <iostream>
#include <vector>
using namespace std;

void subsets(int* input, int n, int idx, vector<int> list, vector<vector<int>> &output){
	if(idx == n){
		output.push_back(list);
		return;
	}
	subsets(input, n, idx+1, list, output);
	list.push_back(input[idx]);
	subsets(input, n, idx+1, list, output);
	list.pop_back();
}

int main(){
	int n;
	cout<<"Enter the value of n: ";
	cin>>n;
	int* input = new int[n];
	for(int i = 0; i < n; i++){
		cin>>input[i];
	}
	vector<int> list;
	vector<vector<int>> output;
	subsets(input, n, 0, list, output);
	for(int i = 0; i < output.size(); i++){
		for(int j = 0; j < output[i].size(); j++){
			cout<<output[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}