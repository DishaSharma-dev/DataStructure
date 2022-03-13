/* Print Specific Pattern
Given a "complete" binary tree , print the following pattern using its all nodes.
Input: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
Output: 1 2 3 4 7 5 6 8 15 9 14 10 13 11 12
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

void pattern(BinaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	queue<BinaryTreeNode<int>*> q1;
	queue<BinaryTreeNode<int>*> q2;
	if(root->left != NULL){
		q1.push(root->left);
	}
	if(root->right != NULL){
		q2.push(root->right);
	}
	while(!q1.empty() || !q2.empty()){
		int n1 = q1.size();
		int n2 = q2.size();
		while(n1 > 0 || n2 > 0){
			if(n1 > 0){
				BinaryTreeNode<int>* x = q1.front();
				q1.pop();
				cout<<x->data<<" ";
				if(x->left != NULL){
					q1.push(x->left);
				}
				if(x->right != NULL){
					q1.push(x->right);
				}
				n1--;
			}
			if(n2 > 0){
				BinaryTreeNode<int>* y = q2.front();
				q2.pop();
				cout<<y->data<<" ";
				if(y->right != NULL){
					q2.push(y->right);
				}
				if(y->left != NULL){
					q2.push(y->left);
				}
				n2--;
			}
		}
	}
}


int main(){
	BinaryTreeNode<int>* root = takeInput();
	cout<<"Pattern is: ";
	pattern(root);
	return 0;
}
