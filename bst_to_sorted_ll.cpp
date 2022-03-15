/* BST to sorted ll
Given a BST, convert it into a sorted linked list. You have to return the head of LL.
Input: 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Output: 2 5 6 7 8 10
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>

class BinaryTreeNode{
	public:
		T data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;
	BinaryTreeNode(T data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

template <typename T>
class Node{
	public:
		T val;
		Node* next;
	Node(T val){
		this->val = val;
		this->next = NULL;
	}
};

class Base{
	public: 
	Node<int>* head;
	Node<int>* tail;
	Base(){
		head = NULL;
		tail = NULL;
	}
};


BinaryTreeNode<int>* takeInput(){
	int data;
	cout<<"Enter data";
	cin>>data;
	if(data == -1){
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	while(q.size() != 0){
		BinaryTreeNode<int>* front = q.front();
		q.pop();
		int leftChild;
		cout<<"Enter the left child of "<<front->data<<": ";
		cin>>leftChild;
		if(leftChild != -1){
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChild);
			front->left = child;
			q.push(child);
		}
		int rightChild;
		cout<<"Enter the right child of "<<front->data<<": ";
		cin>>rightChild;
		if(rightChild != -1){
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChild);
			front->right = child;
			q.push(child);
		}
	}
	return root;
}

Base constructLLFromBST(BinaryTreeNode<int>* root){
	Base combinedList;
	if(root == NULL){
		return combinedList;
	}
	Base leftList = constructLLFromBST(root->left);
	Base rightList = constructLLFromBST(root->right);
	Node<int>* newNode = new Node<int>(root->data);
	if(leftList.tail != NULL){
		leftList.tail->next = newNode;
	}
	newNode->next = rightList.head;
	if(leftList.head != NULL){
		combinedList.head = leftList.head;
	}
	else{
		combinedList.head = newNode;
	}
	if(rightList.tail != NULL){
		combinedList.tail = rightList.tail;
	}
	else{
		combinedList.tail = newNode;
	}
	return combinedList;
}

void print(Node<int>* head){
	Node<int>* temp = head;
	while(temp != NULL){
		cout<<temp->val<<" ";
		temp = temp->next;
	}
}

int main(){
	BinaryTreeNode<int>* root = takeInput();
	Node<int>* head = constructLLFromBST(root).head;
	print(head);
	return 0;
}