/* Dynamic Queue */

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
				T* newdata = new T[2*capacity];
				int j = 0;
				for(int i = frontIndex; i < capacity; i++){
					newdata[j] = data[i];
					j++;
				}
				for(int i = 0; i < frontIndex; i++){
					newdata[j] = data[i];
					j++;
				}
				delete []data;
				data = newdata;
				frontIndex = 0;
				nextIndex = capacity;
				capacity *= 2;
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
	q.enqueue(100);
	q.enqueue(90);
	q.enqueue(80);
	q.enqueue(10);
	q.enqueue(20);
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);
	cout<<q.front()<<endl;
	cout<<q.getSize()<<endl;
	cout<<q.isEmpty()<<endl;
	return 0;
}