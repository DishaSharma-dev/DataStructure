/* Combinational Sum
Given an array of integers A and an integer B. Find and return all unique combinations in A where 
the sum of elements is equal to B.Elements of input array can be repeated any number of times.
One combination should be saved in increasing order. Order of different combinations doesn't matter.
Input: 4
       2 4 6 8
       8
Output: 2 2 2 2 
        2 2 4 
        2 6 
        4 4 
        8
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void combinationalSum(int i, int sum, vector<vector<int>> &ans, vector<int> &list, vector<int> arr){
	if(sum < 0) return;
	if(sum == 0){
		ans.push_back(list);
		return;
	}
	while(i < arr.size() && sum-arr[i] >= 0){
		list.push_back(arr[i]);
		combinationalSum(i, sum - arr[i], ans, list, arr);
		i++;
		list.pop_back();
	}
}

int main(){
	int n, sum;
	cout<<"Enter the value of n: ";
	cin>>n;
	vector<int> arr(n);
	cout<<"Enter the elements: ";
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	cout<<"Enter the sum: ";
	cin>>sum;
	vector<vector<int>> ans;
	vector<int> list;
	sort(arr.begin(), arr.end());
	vector<int>::iterator ip;
	ip = std::unique(arr.begin(), arr.begin() + n);
	arr.resize(std::distance(arr.begin(), ip));
	combinationalSum(0, sum, ans, list, arr);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
