/* Print ith Node
For a given a singly linked list of integers and a position 'i', print the node data at the 'i-th' position.
Input: 3 4 5 2 6 1 9 -1
       3
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

int ith_node(Node* head,int pos){
	int count = 0;
	Node* temp = head;
	while(count != pos){
		count++;
		temp = temp->next;
	}
	return temp->data;
}

int main(){
	int pos;
	cout<<"Enter the input: ";
	Node* head = takeInput();
	cout<<"Enter the position of the element: ";
	cin>>pos;
	cout<<"The Element is: ";
	cout<<ith_node(head,pos);
	return 0;
}