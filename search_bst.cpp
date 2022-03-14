/* Search in BST
Given a BST and an integer k. Find if the integer k is present in given BST or not.
You have to return true, if node with data k is present, return false otherwise.
Input: 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
	   2
Output: true
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

bool search(BinaryTreeNode<int>* root, int k){
	if(root == NULL){
		return false;
	}
	if(root->data == k){
		return true;
	}
	if(k > root->data){
		search(root->right, k);
	}
	else{
		search(root->left, k);
	}
}

int main(){
	BinaryTreeNode<int>* root = takeInput();
	cout<<"Enter the node to be search: ";
	int k;
	cin>>k;
	int output = search(root, k);
	if(output == 0){
		cout<<"Not found";
	}
	else{
		cout<<"It is found";
	}
	return 0;
}