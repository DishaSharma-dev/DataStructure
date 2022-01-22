/* Stack using LinkedList */

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
class stackUsingLL{
	Node<T>* head;
	int size;
	public:
		stackUsingLL(){
			head = NULL;
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
		void push(T ele){
			Node<T>* newnode = new Node<T>(ele);
			if(head == NULL){
				newnode->next = head;
				head = newnode;
			}
			else{
				newnode->next = head;
				head = newnode;
			}
			size++;
		}
		T pop(){
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
		T top(){
			if(head == NULL){
				return -1;
			}
			return head->data;
		}
};

int main(){
	stackUsingLL<int> sa;
	int ch;
	while(1){
		cout<<"Enter your choice: \n";
		cout<<"1. Insert an element: \n";
		cout<<"2. Delete an element: \n";
		cout<<"3. Size of Stack: \n";
		cout<<"4. Top element: \n";
		cout<<"5. Check whether Empty Stack or not: \n";
		cout<<"6. Exit: \n";
		cin>>ch;
		switch(ch){
			case 1 : int ele;
			         cout<<"Enter the element: "<<endl;
			         cin>>ele;
			         sa.push(ele);
			         break;
			case 2 : cout<<sa.pop()<<endl;
			         break;
			case 3 : cout<<sa.getSize()<<endl;
			         break;
			case 4 : cout<<sa.top()<<endl;
			         break;
			case 5 : cout<<sa.isEmpty()<<endl;
			         break;
			case 6 : exit(0);
		}
	}
	return 0;
}