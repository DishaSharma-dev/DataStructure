/* Bubble Sort(Iterative) LinkedList
Given a singly linked list of integers, sort it using 'Bubble Sort.'
Input: 10 9 8 7 6 5 4 3 -1
Output:  3 4 5 6 7 8 9 10 */

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

Node* bubbleSort(Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	int n = length(head);
	for(int  i = 1; i <= n-1; i++){
		Node* temp = head;
		Node*prev = NULL;
		while(temp->next != NULL){
			if(temp->data > temp->next->data){
				if(prev != NULL){
					Node* fwd = temp->next;
					prev->next = fwd;
					temp->next = fwd->next;
					fwd->next = temp;
					prev = fwd;
				}
				else{
					Node* fwd = head->next;
					head->next = fwd->next;
					fwd->next = head;
					head = fwd;
					prev = head;
				}
			}
			else{
				prev = temp;
				temp = temp->next;
			}
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
	head = bubbleSort(head);
	cout<<"Updated List is: ";
	print(head);
	return 0;
}      