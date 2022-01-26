/* Sort a stack using temp stack*/

#include <iostream>
#include <stack>
using namespace std;

stack<int> sortStack(stack<int> s){
	stack<int> output;
	while(!s.empty()){
		int temp = s.top();
		s.pop();
		while(!output.empty() && output.top() < temp){
			s.push(output.top());
			output.pop();
		}
		output.push(temp);
	}
	return output;
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
	stack<int> s1 = sortStack(s);
	cout<<"Stack after sorting: \n";
	while(!s1.empty()){
		cout<<s1.top()<<" ";
		s1.pop();
    }
	return 0;
}