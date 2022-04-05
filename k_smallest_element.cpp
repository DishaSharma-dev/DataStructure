/* K smallest elements
You are given with an integer k and an array of integers that contain numbers in random order. 
Write a program to find k smallest numbers from given array. You need to save them in an array and 
return it.
Time complexity should be O(n * logk) and space complexity should not be more than O(k).
Input: 13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
Output: 1 2 3 5 
*/

#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;
void kSmallest(int* &arr, int n, int k){
	int i;
	for(i = 0; i < k; i++){
		pq.push(arr[i]);
	}
	for(i = k; i < n; i++){
		int ans = pq.top();
		if(arr[i] < ans){
			pq.pop();
			pq.push(arr[i]);
		}
	}
}

int main(){
	int n, k;
	cout<<"Enter the size of an array: ";
	cin>>n;
	cout<<"Enter the elements: ";
	int* arr = new int[n];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	cout<<"Enter the value of k: ";
	cin>>k;
	kSmallest(arr, n, k);
	cout<<"Output is: ";
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	return 0;
}