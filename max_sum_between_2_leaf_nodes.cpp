/* Maximum Sum in binay tree
Given a binary tree, such that each node contains an integer.
Find and return the maximum possible sum in going from one leaf node to another.
You can chose any two leaf nodes from input tree.
If root is NULL, return -Infinity.
Input: -15 5 6 -8 1 3 9 2 6 -1 -1 -1 -1 -1 0 -1 -1 -1 -1 4 -2 -1 -1 10 -1 -1 -1 
Output: 26
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

int maxSumBetweenTwoLeaves = 0;

int maxSumPath(BinaryTreeNode<int>* root){
	if(root == NULL){
		return 0;
	}
	if(root->left == NULL && root->right == NULL){
		return root->data;
	}
	int l = maxSumPath(root->left);
	int r = maxSumPath(root->right);
	if(root->left != NULL && root->right != NULL){
		maxSumBetweenTwoLeaves = max(maxSumBetweenTwoLeaves, l + r + root->data);
		return max(l,r) + root->data;
	}
	return (root->left != NULL) ? l + root->data : r + root->data;
}

int main(){
	BinaryTreeNode<int>* root = takeInput();
	maxSumPath(root);
	cout<<"Output is: "<<maxSumBetweenTwoLeaves;
	return 0;
}