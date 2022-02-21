/* Print Subsets sum upto k 
Input: 9
       5 12 3 17 1 18 15 3 17 
Output: 3 3
        5 1
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
	int n, k;
	cout<<"Enter the value of n: ";
	cin>>n;
	int* input = new int[n];
	for(int i = 0; i < n; i++){
		cin>>input[i];
	}
	cout<<"Enter the value of k: ";
	cin>>k;
	vector<int> list;
	vector<vector<int>> output;
	int sum = 0;
	subsets(input, n, 0, list, output);
	for(int i = 0; i < output.size(); i++){
		for(int j = 0; j < output[i].size(); j++){
			if(output[i][j] != ' '){
				sum += output[i][j];
			}
		}
		if(sum == k){
			for(int j = 0; j < output[i].size(); j++){
				cout<<output[i][j]<<" ";
			}	
			cout<<endl;
		}
		sum = 0;
	}
	return 0;
}