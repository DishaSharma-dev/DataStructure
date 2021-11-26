/* Midpoint of LL
For a given singly linked list of integers, find and return the node present at the middle of the list.
Input: 1 2 3 4 5 -1
Output: 3*/

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

Node* midpoint(Node* head){
	if(head == NULL || head->next == NULL){
		return NULL;
	}
	Node* slow = head;
	Node* fast = head->next;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

int main(){
	cout<<"Enter the List: ";
	Node* head = takeInput();
	Node* index = midpoint(head);
	cout<<index->data;
	return 0;
}


 
