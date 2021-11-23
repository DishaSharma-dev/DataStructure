/* Delete every N nodes 
You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' 
Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes.
Continue the same until the end of the linked list.
To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.
Input: 1 2 3 4 5 6 7 8 -1
       2 2
Output: 1 2 5 6
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

void print(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

Node* skipMdeleteN(Node* head, int m, int n){
	if(m == 0 || head == NULL){
		return NULL;
	}
	if(n == 0){
		return head;
	}
	Node* curr = head;
	Node* temp = NULL;
	while(curr != NULL){
		int take = 0;
		int skip = 0;
		while(curr != NULL && take < m){
			if(temp == NULL){
				temp = curr;
			}
			else{
				temp->next = curr;
				temp = curr;
			}
			curr = curr->next;
			take++;
		}
		while(curr != NULL && skip < n){
			Node* newNode = curr;
			delete curr;
			curr = newNode->next;
			skip++;
		}
	}
	if(temp != NULL){
		temp->next = NULL;
	}
	return head;
}

int main(){
	int m,n;
	cout<<"Enter the input: ";
	Node* head = takeInput();
	cout<<"Enter the value of M: ";
	cin>>m;
	cout<<"Enter the value of N: ";
	cin>>n;
	head = skipMdeleteN(head,m,n);
	cout<<"Updated List is: ";
	print(head);
	return 0;
}


 
