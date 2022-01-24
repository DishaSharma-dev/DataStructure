/* Queue using Array */

#include <iostream>
using namespace std;

template<typename T>

class QueueUsingArray{
	T* data;
	int size;
	int nextIndex;
	int frontIndex;
	int capacity;
	public:
		QueueUsingArray(int s){
			data = new T[s];
			size = 0;
			capacity = s;
			nextIndex = 0;
			frontIndex = -1;
		}
		int getSize(){
			return size;
		}
		bool isEmpty(){
			return size == 0;
		}
		void enqueue(T item){
			if(size == capacity){
				cout<<"Queue is full\n";
				return;
			}
			data[nextIndex] = item;
			nextIndex = (nextIndex + 1) % capacity;
			if(frontIndex == -1){
				frontIndex = 0;
			}
			size++;
		}
		T front(){
			if(isEmpty()){
				cout<<"Queue is empty"<<endl;
	            return 0;
			}
			return data[frontIndex];
		}
		T dequeue(){
			if(isEmpty()){
				cout<<"Queue is empty"<<endl;
	            return 0;
			}
			T ans = data[frontIndex];
			frontIndex = (frontIndex + 1) % capacity;
			size--;
			if(size == 0){
				frontIndex = -1;
				nextIndex = 0;
			}
			return ans;
		}
};

int main(){
	QueueUsingArray<int> q(5);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);
	cout<<q.front()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.getSize()<<endl;
	cout<<q.isEmpty()<<endl;
	return 0;
}