/* Stack using single queue */

#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueues{
	queue<int> q1;
	public:
		bool isEmpty(){
			if(q1.size() == 0){
				return false;
			}
			return true;
		}
		int getSize(){
			return q1.size();
		}
		void push(int ele){
			q1.push(ele);
			for(int i = 0; i < q1.size()-1; i++){
				q1.push(q1.front());
				q1.pop();
			}
		}
		int pop(){
			int val = q1.front();
			q1.pop();
			return val;
		}
		int top(){
			if(q1.size() == 0){
				return -1;
			}
			return q1.front();
		}
};

int main(){
	int n;
	cout<<"Enter the size: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements:";
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	StackUsingQueues s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout<<s.pop()<<endl;
	s.push(4);
	s.push(5);
	cout<<s.pop()<<endl;
	cout<<s.getSize()<<endl;
	cout<<s.isEmpty()<<endl;
	cout<<s.top()<<endl;
	return 0;
}