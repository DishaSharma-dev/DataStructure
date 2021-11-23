/* Let last be the first
Write a function that moves last element to front in a given singly Linked List.
For example, if the given Linked List is 1->2->3->4->5, then the function should change the list to 5->1->2->3->4.
You just need to return the head of new linked list, don't print the elements.
Input: 1 2 3 4 5 6 -1
Output: 6 1 2 3 4 5
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

Node* lastToFirst(Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	if(head->next->next == NULL){
		Node* temp = head;
		head = head->next;
		head->next = temp;
		head->next->next = NULL;
		return head;
	}
	Node* temp = head;
	while(temp->next->next != NULL ){
		temp = temp->next;
	}
	Node* a = head;
	head = temp->next;
	head->next = a;
	temp->next = NULL;
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
	cout<<"Enter the input: ";
	Node* head = takeInput();
	head = lastToFirst(head);
	cout<<"Updated List is: ";
	print(head);
	return 0;
}


 