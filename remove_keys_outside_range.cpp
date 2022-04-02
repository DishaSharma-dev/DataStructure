/* Remove keys outside range
Given a Binary Search Tree (BST) and a range [min, max], remove all keys which are outside the given range.
The resultant tree should also be BST. Return the root of the resultant BST.
Input: 9 -10 17 -1 -5 16 18 -1 -1 10 -1 -1 -1 -1 -1
	   -7 16
Output: -5 9 10 16
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

BinaryTreeNode<int>* removeOutsideRange(BinaryTreeNode<int>* root, int mini, int maxi){
	if(root == NULL) return NULL;
	root->left = removeOutsideRange(root->left, mini, maxi);
	root->right = removeOutsideRange(root->right, mini, maxi);
	if(root->data < mini){
		return root->right;
	}
	if(root->data > maxi){
		return root->left;
	}
	return root;
}

void printTree(BinaryTreeNode<int>* root){
	if(root == NULL) return;
	printTree(root->left);
	cout<<root->data<<" ";
	printTree(root->right);
}

int main(){
	BinaryTreeNode<int>* root = takeInput();
	int mini, maxi;
	cout<<"Enter the minimum: ";
	cin>>mini;
	cout<<"Enter the maximum: ";
	cin>>maxi;
	BinaryTreeNode<int>* new_root = removeOutsideRange(root, mini, maxi);
	printTree(new_root);
	return 0;
}
