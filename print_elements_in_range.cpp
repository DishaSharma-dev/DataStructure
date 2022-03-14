/* Print Elements in Range
Given a Binary Search Tree and two integers k1 and k2, find and print the elements which are in range k1 
and k2 (both inclusive).
Print the elements in increasing order.
Input: 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
       6 10
Output: 6 7 8 10
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

void elementsInRange(BinaryTreeNode<int>* root, int k1, int k2){
	if(root == NULL){
		return;
	}
	if(root->data >= k1 && root->data <= k2){
		elementsInRange(root->left, k1, k2);
		cout<<root->data<<" ";
		elementsInRange(root->right, k1, k2);
	}
	else if(root->data < k1){
		elementsInRange(root->right, k1, k2);
	}
	else{
		elementsInRange(root->left, k1, k2);
	}
}

int main(){
	BinaryTreeNode<int>* root = takeInput();
	int k1, k2;
	cout<<"Enter min Range element: ";
	cin>>k1;
	cout<<"Enter max Range element: ";
	cin>>k2;
	elementsInRange(root, k1, k2);
	return 0;
}