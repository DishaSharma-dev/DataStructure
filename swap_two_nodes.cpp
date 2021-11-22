/* Swap two nodes of linked list
You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' 
Swap the nodes that are present at the 'i-th' and 'j-th' positions.
Input: 3 4 5 2 6 1 9 -1
       3 4
Output: 3 4 5 6 2 1 9 
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

Node* swapNode(Node* head, int i, int j){
	if(head == NULL || head->next == NULL || (i == j)){
		return head;
	}
	if(abs(i-j) == 1 && i == 0){
		Node* temp = head->next;
		head->next = temp->next;
		temp->next = head;
		head = temp;
		return head;
	}
	if(abs(i-j) == 1){
		Node* curr = head;
		Node* prev = head;
		int count = 0;
		while(count < i && curr != NULL){
			prev = curr;
			curr= curr->next;
			count++;
		}
		if(curr != NULL){
			Node* temp = curr->next;
			prev->next = temp;
			curr->next = temp->next;
			temp->next = curr;
		}
		return head;
	}
	else{
		int count = 0;
		Node* curr1 = head;
		Node* prev1 = head;
		while(count < i && curr1 != NULL){
			prev1 = curr1;
			curr1 = curr1->next;
			count++;
		}
		count = 0;
		Node* prev2 = head;
		Node* curr2 = head;
		while(count < j && curr2 != NULL){
			prev2 = curr2;
			curr2 = curr2->next;
			count++;
		}
		if(i == 0){
			Node* temp = head->next;
			prev2->next = head;
			head->next = curr2->next;
			curr2->next = temp;
			head = curr2;	
		}
		else if(curr1!= NULL && curr2 != NULL){
			Node* temp = curr2->next;
			prev1->next = curr2;
			prev2->next = curr1;
			curr2->next = curr1->next;
			curr1->next = temp;
		}
		return head;
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
	int index1,index2;
	cout<<"Enter the input: ";
	Node* head = takeInput();
	cout<<"Enter the index1 of the element to be swapped: ";
	cin>>index1;
	cout<<"Enter the index1 of the element to be swapped: ";
	cin>>index2;
	head = swapNode(head , index1, index2);
	cout<<"Updated List is: ";
	print(head);
	return 0;
}

