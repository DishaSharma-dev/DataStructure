/* Swap every pair
Given a Linked list, swap every pair of nodes to form a new linked list. That is, swap first two nodes,
then 2nd two nodes and so on. If the size of linked list is odd, then leave the last node as it is.
Input: 1 2 3 4 5 6 -1
Output: 2 1 4 3 6 5
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


Node* swap(Node* head){
	Node* dummy = new Node(-1);
	Node* prev = dummy;
	Node* curr = head;
	dummy->next = head;
	while(curr != NULL && curr->next != NULL){
		prev->next = curr->next;
		curr->next = curr->next->next;
		prev->next->next = curr;
		curr = curr->next;
		prev = prev->next->next;
	}
	return dummy->next;
}


void print(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

int main(){
	int n;
	cout<<"Enter the List: ";
	Node* head = takeInput();
	head = swap(head);
	cout<<"Updated List is: ";
	print(head);
	return 0;
}      