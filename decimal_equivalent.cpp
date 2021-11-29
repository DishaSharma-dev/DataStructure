/* Decimal Equivalent
Given a singly linked list of 0s and 1s, find and return its decimal equivalent.
Input: 1 0 -1
Output: 2
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

int decimalEquivalent(Node* head){
	int ans = 0;
	while(head != NULL){
		ans = (ans << 1) + head->data;
		head = head->next;
	}
	return ans;
}

int main(){
	int n;
	cout<<"Enter the List: ";
	Node* head = takeInput();
	int out = decimalEquivalent(head);
	cout<<out;
	return 0;
}      