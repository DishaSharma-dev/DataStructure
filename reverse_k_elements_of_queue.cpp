/* Reverse k elements of queue 
Input: 1 2 3 4 5
       3
Output: 3 2 1 4 5
*/

#include <iostream>
#include <queue>
using namespace std;

int reverse(queue<int>& q, int k){
	if(k == 0){
		return 0;
	}
	int val = q.front();
	q.pop();
	reverse(q, --k);
	q.push(val);
}

int main(){
	int n, k;
	queue<int> q;
	cout<<"Enter the size of queue: ";
	cin>>n;
	cout<<"Enter the value of k:";
	cin>>k;
	cout<<"Enter the elements: ";
	for(int i = 0; i < n; i++){
		int ele;
		cin>>ele;
		q.push(ele);
	}
	reverse(q, k);
	for(int i = 0; i < n-k; i++){
		int val = q.front();
		q.pop();
		q.push(val);
	}
	cout<<"Reverse queue is: ";
	for(int i = 0; i < n; i++){
		cout<<q.front()<<" ";
		q.pop();
	}
	return 0;
}