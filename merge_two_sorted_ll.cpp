/* Merge two Sorted LL
You have been given two sorted(in ascending order) singly linked lists of integers.
Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order)
and return the new head to the list.
Input: 2 5 8 12 -1
       3 6 9 -1
Output: 2 3 5 6 8 9 12 */

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

Node* mergeList(Node* head1, Node* head2){
	if(head1 == NULL){
		return head2;
	}
	if(head2 == NULL){
		return head1;
	}
    Node* head = NULL;
    Node* tail = NULL;
	while(head1 != NULL && head2 != NULL){
		if(head1->data > head2->data){
			if(tail == NULL){
				head = head2;
				tail = head2;
				head2 = head2->next;	
			}
			else{
				tail->next = head2;
				head2 = head2->next;
				tail = tail->next;
			}	
		}
		else{
			if(tail == NULL){
				head = head1;
				tail = head1;
				head1 = head1->next;	
			}
			else{
				tail->next = head1;
				head1 = head1->next;
				tail = tail->next;
			}
		}
	}
	if(head1 != NULL){
		tail->next = head1;
	}
	if(head2 != NULL){
		tail->next = head2;
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
	cout<<"Enter the List1: ";
	Node* head1 = takeInput();
	cout<<"Enter the List2: ";
	Node* head2 = takeInput();
	Node* head = mergeList(head1, head2);
	cout<<"Updated List is: ";
	print(head);
	return 0;
}


 
