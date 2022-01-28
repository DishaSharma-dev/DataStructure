/* Reverse Stack using Recursion*/

#include <iostream>
#include <stack>
using namespace std;

int insertAtBottom(stack<int>& s, int temp){
	if(s.empty()){
		s.push(temp);
		return 0;
	}
	int val = s.top();
	s.pop();
	insertAtBottom(s, temp);
	s.push(val);
}

int reverse(stack<int>& s){
	if(s.empty()){
		return 0;
	}
	int temp = s.top();
	s.pop();
	reverse(s);
	insertAtBottom(s, temp);
}

int main(){
	stack<int> s;
	int n;
	cout<<"Enter the size: ";
	cin>>n;
	cout<<"Enter the elements: ";
	for(int i = 0; i < n; i++){
		int ele;
		cin>>ele;
		s.push(ele);
	}
	reverse(s);
	for(int i = 0; i < n; i++){
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}