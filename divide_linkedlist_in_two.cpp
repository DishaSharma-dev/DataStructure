/*Divide Linked List in two
Write a function that takes one list and divides up its nodes to create two smaller lists A and B. 
The sub lists should be made from alternating elements in the original list.
Input : 8 2 5 9 1 4 3 7 -1
Output:  3 1 5 8
         7 4 9 2
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

Node* reverse(Node* head){
	Node* curr = head;
	Node* prev = NULL;
	while(curr != NULL){
		Node* temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	return prev;
}

void print(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

void divide(Node* head){
	int count = 0;
	Node* temp = head;
	Node* head1 = NULL;
	Node* tail1 = NULL;
	Node* head2 = NULL;
	Node* tail2 = NULL;
	while(temp != NULL){
		if(count%2 == 0){
			if(head1 == NULL){
				head1 = temp;
				tail1 = temp; 
				count++;
			}
			else{
				tail1->next = temp;
				tail1 = temp;
				count++;
			}
		}
		else{
			if(head2 == NULL){
				head2 = temp;
				tail2 = temp; 
				count++;
			}
			else{
				tail2->next = temp;
				tail2 = temp;
				count++;
			}
		}
		temp = temp->next;
	}
	tail1->next = NULL;
	tail2->next = NULL;
	print(head2);
	cout<<endl;
	print(head1);
}


int main(){
	cout<<"Enter the input: ";
	Node* head = takeInput();
	if(head->next == NULL){
		return head->data;
	}
	else{
		head = reverse(head);
		divide(head);
	}
	return 0;
}


 