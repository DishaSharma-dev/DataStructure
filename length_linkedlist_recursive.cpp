/* Length of Linked List (Recursion)
For a given singly linked list of integers, find and return its length. Do it using an iterative method.
Input : 3 4 5 2 6 1 9 -1
Output: 7
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

int lengthLL(Node* head){
	if(head == NULL){
		return 0;
	}
	return 1 + lengthLL(head->next);
}

int main(){
	cout<<"Enter the input: ";
	Node* head = takeInput();
	cout<<"Length of Linked List is: ";
	cout<<lengthLL(head);
	return 0;
}