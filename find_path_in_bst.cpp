/* Find Path in BST
Given a BST and an integer k. Find and return the path from the node with data k and root
(if a node with data k is present in given BST) in a list.
Return empty list otherwise.
Input: 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
	   2
Output: 2 5 8
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

vector<int>* getPath(BinaryTreeNode<int>* root, int data){
	if(root == NULL){
		return NULL;
	}
	if(root->data == data){
		vector<int>* output = new vector<int>();
		output->push_back(root->data);
		return output;
	}
	if(root->data < data){
		vector<int>* rightOutput = getPath(root->right, data);
		if(rightOutput != NULL){
			rightOutput->push_back(root->data);
			return rightOutput;
		}
		else return NULL;
	}
	else{
		vector<int>* leftOutput = getPath(root->left, data);
		if(leftOutput != NULL){
			leftOutput->push_back(root->data);
			return leftOutput;
		}
		else return NULL;
	}
}

int main(){
	int data;
	BinaryTreeNode<int>* root = takeInput();
	cout<<"Enter the node to find";
	cin>>data;
	vector<int>* output = getPath(root, data);
	for(int i = 0; i < output->size(); i++){
		cout<<output->at(i)<<" ";
	}
	return 0;
}