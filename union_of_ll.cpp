/* Union of two Linked list
Given a two Linked Lists, find out union of both given input lists and return the new Linked List.
Input: 1 2 3 4 -1
       8 7 5 3 -1
Output: 1
		2
		3
		4
		8
		7
		5*/

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

Node* unionList(Node* head1, Node* head2){
	if(head1 == NULL){
		return head2;
	}
	if(head2 == NULL){
		return head1;
	}
	else{
		Node* temp = head1;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = head2;
		return head1;
	}
}

void print(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

int main(){
	cout<<"Enter the List1: ";
	Node* head1 = takeInput();
	cout<<"Enter the List2: ";
	Node* head2 = takeInput();
	Node* head = unionList(head1, head2);
	cout<<"Updated List is: ";
	print(head);
	return 0;
}


 
