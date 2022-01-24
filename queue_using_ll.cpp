/* Queue Using LinkedList*/

#include <iostream>
using namespace std;

template<typename T>
class Node{
	public:
		T data;
		Node<T>* next;
		Node(T data){
			this->data = data;
			this->next = NULL;
		}
};

template<typename T>
class QueueUsingLL{
	Node<T>* head;
	Node<T>* tail;
	int size;
	public:
		QueueUsingLL(){
			head = NULL;
			tail = NULL;
			size = 0;
		}
		bool isEmpty(){
			if(head == NULL){
				return true;
			}
			return false;
		}
		int getSize(){
			return size;
		}
		void enqueue(T ele){
			Node<T>* newnode = new Node<T>(ele);
			if(head == NULL){
				head = newnode;
				tail = newnode;
			}
			else{
				tail->next = newnode;
				tail = newnode;
			}
			size++;
		}
		T dequeue(){
			if(head == NULL){
				return -1;
			}
			T ans = head->data;
			Node<T>* temp = head;
			head = head->next;
			delete temp;
			size--;
			return ans;
		}
		T front(){
			if(head == NULL){
				return -1;
			}
			return head->data;
		}
};

int main(){
	QueueUsingLL<int> q;
//	q.enqueue(17);
//	q.enqueue(23);
//	q.enqueue(11);
//	cout<<q.dequeue()<<endl;
//	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
    cout<<q.front()<<endl;
	cout<<q.dequeue()<<endl;
	q.enqueue(1);
	cout<<q.getSize();
	return 0;
}