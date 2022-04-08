/* Running Median
You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers,
print the resulting median.
Print only the integer part of the median.
Input: 6
6 2 1 3 7 5
Output: 6 4 2 2 3 4
Explanation: S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4*/

#include <bits/stdc++.h>
using namespace std;

void findMedian(int* arr, int n){
	priority_queue<int, vector<int>, greater<int>> p1;
	priority_queue<int> p2;
	for(int i = 0; i < n; i++){
		if(p2.size() && arr[i] > p2.top()){
			p1.push(arr[i]);
		}
		else{
			p2.push(arr[i]);
		}
		if(abs((int)p1.size() - (int)p2.size()) > 1){
			if(p1.size() > p2.size()){
				int ans = p1.top();
				p1.pop();
				p2.push(ans);
			}
			else{
				int ans = p2.top();
				p2.pop();
				p1.push(ans);
			}
		}
		if(p2.size() < p1.size()){
			cout<<p1.top()<<" ";
		}
		else if(p2.size() > p1.size()) cout<<p2.top()<<" ";
		else{
			cout<<(p2.top() + p1.top())/2<<" ";
		}
	}
}

int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int* arr = new int[n];
	cout<<"Enter the elements: ";
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	findMedian(arr, n);
	return 0;
}