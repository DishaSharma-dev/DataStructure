/* Convert Binary Tree to Binary Search Tree
Given a Binary Tree, convert it to a Binary Search Tree. The structure of the Binary Search Tree and 
the Binary Tree must be same. Return root of the resultant BST.
Input: 4 7 6 5 3 2 1 -1 -1 -1 -1 -1 -1 -1 -1
Output: 1 2 3 4 5 6 7
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

void inorderTraversal(BinaryTreeNode<int>* root, vector<int> &nodes){
	if(root == NULL) return;
	inorderTraversal(root->left, nodes);
	nodes.push_back(root->data);
	inorderTraversal(root->right, nodes);
}

void helper(BinaryTreeNode<int>* root, vector<int> nodes){
	static int i = 0;
	if(root == NULL) return;
	helper(root->left, nodes);
	root->data = nodes[i];
	i++;
	helper(root->right, nodes);
}

BinaryTreeNode<int>* convert_bt_bst(BinaryTreeNode<int>* root, vector<int> nodes){
	if(root == NULL) return NULL;
	inorderTraversal(root, nodes);
	sort(nodes.begin(), nodes.end());
	helper(root, nodes);
	return root;
}

void printTree(BinaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}
	printTree(root->left);
	cout<<root->data<<" ";
	printTree(root->right);
}

int main(){
	vector<int> nodes;
	BinaryTreeNode<int>* root = takeInput();
	BinaryTreeNode<int>* new_root = convert_bt_bst(root, nodes);
	printTree(new_root);
	return 0;
}