/* Delete node
You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'POS'.
Input: 3 4 5 2 6 1 9 -1
Output: 3 4 5 6 1 9
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

Node* deleteNode(Node* head, int pos){
	int count = 0;
	if(pos == 0){
		Node* a = head;
		head = head->next;
		delete a;
		return head;
	}
	Node* temp = head;
	while(temp != NULL && count < pos-1){
		count++;
		temp = temp->next;
	}
	if(temp != NULL){
		Node* a = temp->next;
		Node*b = a->next;
		temp->next = b->next;
		delete a;
	}
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
	int pos;
	cout<<"Enter the input: ";
	Node* head = takeInput();
	cout<<"Enter the position of the element to be deleted: ";
	cin>>pos;
	head = deleteNode(head , pos);
	cout<<"Updated List is: ";
	print(head);
	return 0;
}