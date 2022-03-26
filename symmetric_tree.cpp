/* Symmetric Binary Tree
Given a binary tree, check whether it is symmetric around its center at every level. That means,
return true if the given binary tree and its mirror is exactly same. Otherwise return false.
Input: 1 2 2 3 4 4 3 -1 -1 -1 -1 -1 -1 -1 -1
Output: True
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

bool symmetricTree(BinaryTreeNode<int>* leftTree, BinaryTreeNode<int>* rightTree){
	if(leftTree == NULL || rightTree == NULL){
		return leftTree == rightTree;
	}
	if(leftTree->data != rightTree->data) return false;
	return (symmetricTree(leftTree->left, rightTree->right) && symmetricTree(leftTree->right, rightTree->left));
}

int main(){
	BinaryTreeNode<int>* root = takeInput();
	int output = symmetricTree(root->left, root->right);
	if(output == 1){
		cout<<"True";
	}
	else{
		cout<<"false";
	}
	return 0;
}