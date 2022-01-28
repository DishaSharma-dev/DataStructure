/* Stack using two queues*/

#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueues{
	queue<int> q1;
	queue<int> q2;
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
			q2.push(ele);
			while(!q1.empty()){
				int val = q1.front();
				q2.push(val);
				q1.pop();
			}
			while(!q2.empty()){
				int val = q2.front();
				q1.push(val);
				q2.pop();
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