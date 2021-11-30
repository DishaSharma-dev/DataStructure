/* Next Number
Given a large number represented in the form of a linked list. 
Write code to increment the number by 1 in-place(i.e. without using extra space).
Input: 9 9 9 -1
Output: 1 0 0 0 
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

Node* reverseList(Node* head){
	Node* temp = head;
	if(head->next){
		head = reverseList(temp->next);
		temp->next->next = temp;
		temp->next = NULL;
	}
	return head;
}

Node* nextNumber(Node* head){
	Node* curr = head;
	Node* prev = NULL;
	int carry = 1;
	while(curr != NULL){
		int val = ((curr->data) + carry) % 10;
		carry = ((curr->data) + carry) / 10;
		curr->data = val;
		prev = curr;
		curr = curr->next;
	}
	if(carry){
		Node* tail = new Node(carry);
		prev->next = tail;
	}	
	return reverseList(head);
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
	head = reverseList(head);
	head = nextNumber(head);
	cout<<"Updated List is: ";
	print(head);
	return 0;
}   