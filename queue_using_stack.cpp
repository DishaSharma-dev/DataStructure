/* Queue using Stack*/

#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks{
	stack<int> s1;
	stack<int> s2;
	public:
		bool isEmpty(){
			if(s1.size() == 0){
				return false;
			}
			return true;
		}
		int getSize(){
			return s1.size();
		}
		void enqueue(int ele){
			while(!s1.empty()){
				int val = s1.top();
				s2.push(val);
				s1.pop();
			}
			s1.push(ele);
			while(!s2.empty()){
				int val = s2.top();
				s1.push(val);
				s2.pop();
			}
		}
		int dequeue(){
			int val = s1.top();
			s1.pop();
			return val;
		}
		int front(){
			if(s1.size() == 0){
				return -1;
			}
			return s1.top();
		}
};

int main(){
	QueueUsingStacks q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	cout<<q.dequeue()<<endl;
	q.enqueue(4);
	q.enqueue(5);
	cout<<q.dequeue()<<endl;
	cout<<q.getSize()<<endl;
	cout<<q.isEmpty()<<endl;
	cout<<q.front()<<endl;
	return 0;
}