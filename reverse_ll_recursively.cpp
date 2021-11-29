/* Reverse LinkedList Recursively
Given a singly linked list of integers, reverse it using recursion and return the head to the modified list. 
You have to do this in O(N) time complexity where N is the size of the linked list.
Input: 1 2 3 4 5 6 7 8 -1
Output: 8 7 6 5 4 3 2 1
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

class Pair{
	public:
		Node *head;
		Node *tail;
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

Node* reverse_1(Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	Node* smallAns = reverse_1(head->next);
	Node* temp = smallAns;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = head;
	head->next = NULL;
	return smallAns;
}

Pair reverse_2(Node* head){
	if(head == NULL || head->next == NULL){
		Pair ans;
		ans.head = head;
		ans.tail = head;
		return ans;
	}
	Pair smallAns = reverse_2(head->next);
	smallAns.tail->next = head;
	head->next = NULL;
	Pair ans;
	ans.head = smallAns.head;
	ans.tail = head;
	return ans;
}

Node* better_reverse(Node* head){
	return reverse_2(head).head;
}


Node* reverse_3(Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	Node* smallAns = reverse_3(head->next);
	head->next = head;
	head->next = NULL;
	return smallAns;
}


void print(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

int main(){
	cout<<"Enter the List: ";
	Node* head = takeInput();
	head = better_reverse(head);
	cout<<"Updated List is: ";
	print(head);
	return 0;
}


 

