/* Palindrome LinkedList
You have been given a head to a singly linked list of integers. 
Write a function check to whether the list given is a 'Palindrome' or not.
Input: 9 2 3 3 2 9
Output: true
*/

/* Delete node(recursively)
You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'POS'.
Input: 3 4 5 2 6 1 9 -1
Output: 3 4 5 6 1 9
*/

#include <iostream>
using namespace std;

class ListNode{
	public:
		int data;
		ListNode* next;
		ListNode(int n){
			this->data = n;
			this->next = NULL;
		}
};

ListNode* takeInput(){
	ListNode* head = NULL;
	ListNode* tail = NULL;
	int data;
	cin>>data;
	while(data != -1){
		ListNode* newNode = new ListNode(data);
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

ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
    return prev;
}

 ListNode* mid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL  && fast->next != NULL){
            slow = slow->next;
            fast  = fast->next->next;
        }
        return slow;
    }
    

 string isPalindrome(ListNode* head) {
        if(head->next == NULL){
            return "true";
        }
         ListNode* midValue = mid(head);
         ListNode* last = reverse(midValue);
         ListNode* current = head;
         while(last != NULL){
             if(current->data != last->data){
                 return "false";
             }
             current = current->next;
             last = last->next;
         }
    return "true";
}



int main(){
	int pos;
	cout<<"Enter the input: ";
	ListNode* head = takeInput();
	cout<<isPalindrome(head);
	return 0;
}