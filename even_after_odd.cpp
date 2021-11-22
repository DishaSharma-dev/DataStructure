/* Even after odd linkedList
For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after odd numbers. 
The relative order of the odd and even terms should remain unchanged.
Input: 1 4 5 2 -1
Output: 1 5 4 2
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

Node* evenAfterOdd(Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	Node* EH = NULL;
	Node* OH = NULL;
	Node* ET = NULL;
	Node* OT = NULL;
	Node* temp = head;
	while(temp != NULL){
		if(temp->data % 2 == 0){
			if(EH == NULL){
				EH = temp;
				ET = temp;	
			}
			else{
				ET->next = temp;
				ET = temp;
			}
		}
		else{
			if(OH == NULL){
				OH = temp;
				OT = temp;	
			}
			else{
				OT->next = temp;
				OT = temp;
			}
		}
		temp = temp->next;
	}
	if(EH != NULL){
		ET->next = NULL;
	}
	if(OH != NULL){
		OT->next = EH;
		return OH;
	}
	else{
		return EH;
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
	cout<<"Enter the input: ";
	Node* head = takeInput();
	head = evenAfterOdd(head);
	cout<<"Updated List is: ";
	print(head);
	return 0;
}


 