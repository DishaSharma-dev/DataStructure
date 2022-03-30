/* Remove Nodes
Given a binary tree, a complete path is defined as a path from root to a leaf.
The sum of all nodes on that path is defined as the sum of that path.
Given a number K, you have to remove (prune the tree) all nodes which don't lie in any path with sum>=k.
Input: 1 2 3 4 5 6 7 8 9 -1 -1 12 -1 10 -1 -1 -1 13 14 -1 -1 -1 11 -1 -1 15 -1 -1 -1 -1 -1 
20
Output: 1
2 3
4 6 7
9 12 10
13 14 11
15
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

bool Remove_Node(BinaryTreeNode<int>* root, int sum){
	if(root == NULL){
		if(sum > 0) return false;
		else return true;
	}
	bool lAns = Remove_Node(root->left, sum - root->data);
	bool rAns = Remove_Node(root->right, sum - root->data);
	if(!lAns){
		delete root->left;
		root->left = NULL;
	}
	if(!rAns){
		delete root->right;
		root->right = NULL;
	}
	return lAns || rAns;
}

void printTree(BinaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	while(q.size() != 0){
		BinaryTreeNode<int>* front = q.front();
		cout<<front->data<<": ";
		q.pop();
		if(front->left != NULL){
			cout<<"L: "<<front->left->data;
			q.push(front->left);
		}
		if(front->right != NULL){
			cout<<" R: "<<front->right->data;
			q.push(front->right);
		}
		cout<<endl;
	}	
}

int main(){
	int sum;
	BinaryTreeNode<int>* root = takeInput();
	cout<<"Enter the value of sum";
	cin>>sum;
	Remove_Node(root, sum);
	printTree(root);
	return 0;
}