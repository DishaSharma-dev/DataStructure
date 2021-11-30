/* Insertion Sort(Iteratively) LinkedList
Sort a given linked list using Insertion Sort (iteratively).
Input: 1 4 5 2 -1
Output: 1 2 4 5*/

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

Node* insertionSort(Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	Node* dummy = new Node(-1);
	Node* curr = head;
	Node* prev = dummy;
	dummy->next = head;
	while(curr != NULL){
		if(curr->next != NULL && curr->next->data < curr->data){
			while(prev->next != NULL && prev->next->data < curr->next->data){
				prev = prev->next;
			}
			Node* temp = prev->next;
			prev->next = curr->next;
			curr->next = curr->next->next;
			prev->next->next = temp;
			prev = dummy;
		}
		else{
			curr= curr->next;
		}
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
	head = insertionSort(head);
	cout<<"Updated List is: ";
	print(head);
	return 0;
}      