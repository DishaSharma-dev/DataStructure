/* Merge Sort
 Given a singly linked list of integers, sort it using 'Merge Sort.
Input: 10 9 8 7 6 5 4 3 -1
Output:  3 4 5 6 7 8 9 10 
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

Node* midNode(Node* head){
	Node* slow = head;
	Node* fast = head->next;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

Node* merge(Node* head1, Node* head2){
	Node* temp1 = head1;
	Node* temp2 = head2;
	Node* head = NULL;
	Node* tail = NULL;
	if(head1 == NULL){
		return head2;
	}
	if(head2 == NULL){
		return head1;
	}
	while(temp1 != NULL && temp2 != NULL){
		if(temp1->data > temp2->data){
			if(head == NULL){
				head = temp2;
				tail = temp2;
				temp2 = temp2->next;
			}
			else{
				tail->next = temp2;
				temp2 = temp2->next;
				tail = tail->next;
			}
		}
		else{
			if(head == NULL){
				head = temp1;
				tail = temp1;
				temp1 = temp1->next;
			}
			else{
				tail->next = temp1;
				temp1 = temp1->next;
				tail = tail->next;
			}
		}
	}
	if(temp1 != NULL){
		tail->next = temp1;
	}
	if(temp2 != NULL){
		tail->next = temp2;
	}
	return head;
}

Node* mergeSort(Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	Node* mid = midNode(head);
	Node* half1 = head;
	Node* half2 = mid->next;
	mid->next = NULL;
	half1 = mergeSort(half1);
	half2 = mergeSort(half2);
	Node* finalHead = merge(half1,half2);
	return finalHead;
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
	Node* head1 = mergeSort(head);
	cout<<"Updated List is: ";
	print(head1);
	return 0;
}


 
