/*Move to Last
Given a linked list and a key in it, the task is to move all occurrences of given key to end of linked list, 
keeping order of all other elements same.
Input: 1 2 2 3 4 5 -1
       2 
Output: 1 3 4 5 2 2 */

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

int length(Node* head){
	Node* curr = head;
	int count = 0;
	while(curr != NULL){
		curr = curr->next;
		count++;
	}
	return count;
}

Node* moveToLast(Node* head, int n){
	if(head == NULL || head->next == NULL){
		return head;
	}	
	int len = length(head);
	Node* temp = head;
	while(temp->next != NULL){
		temp= temp->next;
	}
	Node* tail = temp;
	Node* curr = head;
	Node* prev = NULL;
	for(int i = 0; i < len; i++){
		if(curr->data == n){
			if(curr == head){
				Node* fwd = head->next;
				tail->next = head;
				head->next = NULL;
				tail = tail->next;
				head = fwd;
				curr = fwd;
			}
			else{
				Node* fwd = curr->next;
				tail->next = curr;
				curr->next = NULL;
				tail = tail->next;
				prev->next = fwd;
				curr = fwd;	
			}
		}
		else{
			prev = curr;
			curr = curr->next;
		}
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
	int n;
	cout<<"Enter the List: ";
	Node* head = takeInput();
	cout<<"Enter the element ie moved to last: ";
	cin>>n;
	head = moveToLast(head,n);
	cout<<"Updated List is: ";
	print(head);
	return 0;
}      