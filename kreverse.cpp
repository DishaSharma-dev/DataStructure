/* kReverse
Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
'k' is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, should be reversed as well.
 Input: 1 2 3 4 5
        2
 Output: 2 1 4 3 5
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

Node* kReverse(Node* head, int k){
	if(k == 0 || k==1){
		return head;
	}
	int count = 0;
    Node* curr = head;
    Node* fwd = NULL;
    Node* prev = NULL;
    while(count < k && curr != NULL){
    	fwd = curr->next;
    	curr->next = prev;
    	prev = curr;
    	curr = fwd;
    	count++;
	}
	if(fwd != NULL){
		head->next = kReverse(fwd,k);	
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

int main(){
	int k;
	cout<<"Enter the input: ";
	Node* head = takeInput();
	cout<<"Enter the value of k: ";
	cin>>k;
	head = kReverse(head , k);
	cout<<"Updated List is: ";
	print(head);
	return 0;
}


 