/* Sort a stack
Given a stack, sort the elements inside that stack in ascending order using only push and pop operation. 
You can use one additional stack only.
Input: 5
1 2 3 4 5
Output: 1 2 3 4 5
*/

#include <iostream>
#include <stack>
using namespace std;

int put_sorted(int temp, stack<int>& s){
	if(s.empty() || s.top() > temp){
		s.push(temp);
		return 0;
	}
	int val = s.top();
	s.pop();
	put_sorted(temp, s);
	s.push(val);
	return 0;
}

int sortStack(stack<int>& s){
	if(s.empty()){
		return 0;
	}
	int temp = s.top();
	s.pop();
	sortStack(s);
	put_sorted(temp, s);
	return 0;
}

int main(){
	int n;
	cout<<"Enter the size: ";
	cin>>n;
	stack<int> s;
	cout<<"Enter the elements in a stack: \n";
	for(int i = 0; i < n; i++){
		int ele;
		cin>>ele;
		s.push(ele);
	}
	sortStack(s);
	cout<<"Stack after sorting: \n";
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}