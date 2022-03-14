/* Check if Binary Tree is BST
Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree).
If yes, return true, return false otherwise.
Input: 3 1 5 -1 2 -1 -1 -1 -1
Output: true
3 methods are implemented
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

class BSTReturn{
	public:
	bool isBST;
	int maximum;
	int minimum;
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

int minimum(BinaryTreeNode<int>* root){
	if(root == NULL){
		int output = INT_MAX;
		return output;
	}
	return min(root->data, min(minimum(root->left), minimum(root->right)));
}

int maximum(BinaryTreeNode<int>* root){
	if(root == NULL){
		int output = INT_MIN;
		return output;
	}
	return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool checkIfBST1(BinaryTreeNode<int>* root){
	if(root == NULL){
		return true;
	}
	int lmax = maximum(root->left);
	int rmin = minimum(root->right);
	bool output = (lmax < root ->data) && (rmin >= root->data) && checkIfBST1(root->left) && checkIfBST1(root->right);
	return output;
}

BSTReturn checkIfBST2(BinaryTreeNode<int>* root){
	if(root == NULL){
		BSTReturn output;
		output.isBST = true;
		output.minimum = INT_MAX;
		output.maximum = INT_MIN;
		return output;
	}
	BSTReturn leftOutput = checkIfBST2(root->left);
	BSTReturn rightOutput = checkIfBST2(root->right);
	int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum));
	int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
	bool isBST = (leftOutput.maximum < root->data) && (rightOutput.minimum >= root->data) && (leftOutput.isBST) && (rightOutput.isBST);
	BSTReturn output;
	output.isBST = isBST;
	output.maximum = maximum;
	output.minimum = minimum;
	return output;
}

bool checkIfBST3(BinaryTreeNode<int>* root, int mini, int maxi){
	if(root == NULL){
		return true;
	}
	if(root->data < mini || root->data > maxi){
		return false;
	}
	bool leftAns = checkIfBST3(root->left, mini, root->data);
	bool rightAns = checkIfBST3(root->right, root->data, maxi);
	return leftAns & rightAns;
}

int main(){
	BinaryTreeNode<int>* root = takeInput();
//	cout<<checkIfBST1(root);
//  cout<<checkIfBST2(root).isBST;
    cout<<checkIfBST3(root, INT_MIN, INT_MAX);
	return 0;
}
