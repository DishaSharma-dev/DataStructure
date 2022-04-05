/* K sorted array
Input: 5
       10 12 15 6 9
       k = 3
Output: 15 12 10 9 6
*/

#include <iostream>
#include <queue>
using namespace std;

void kSortedArray(int* &arr, int n, int k){
	priority_queue<int> pq;
	int i;
	for(i = 0; i < k; i++){
		pq.push(arr[i]);
	}
	int j = 0;
	for(i = k; i < n; i++){
		arr[j] = pq.top();
		pq.pop();
		j++;
		pq.push(arr[i]);
	}
	while(!pq.empty()){
		arr[j] = pq.top();
		pq.pop();
		j++;
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
	kSortedArray(arr, n, k);
	cout<<"Output is: ";
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}