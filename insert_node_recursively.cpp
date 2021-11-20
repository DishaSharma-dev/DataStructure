/* Insert node(Recursively)
You have been given a linked list of integers. Your task is to write a function that inserts a node at a given position, 'pos'.
Input: 3 4 5 2 6 1 9 -1
       3 100
Output: 3 4 5 100 2 6 1 9
*/

#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node(int n){
			this->data = n;
			this->next = NULL;
		}
};

Node* takeInput(){
	Node* head = NULL;
	Node* tail = NULL;
	int data;
	cin>>data;
	while(data != -1){
		Node* newNode = new Node(data);
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			tail->next = newNode;
			tail = newNode;
		}
		cin>>data;
	}
	return head;
}

Node* insertNode(Node* head, int pos, int data){
	if(head == NULL){
		if(pos == 0){
			Node* newNode = new Node(data);
			return newNode;
		}
		return head;
	}
	Node* a = new Node(data);
	if(pos == 0){
		a->next = head;
		head = a;
		return head;
	}
	head->next = insertNode(head->next,pos-1,data);
	return head;
}

void print(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

int main(){
	int pos,data;
	cout<<"Enter the input: ";
	Node* head = takeInput();
	cout<<"Enter the position of the element to be added: ";
	cin>>pos;
	cout<<"Enter the element";
	cin>>data;
	head = insertNode(head, pos, data);
	cout<<"Updated List is: ";
	print(head);
	return 0;
}