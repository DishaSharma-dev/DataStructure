/* Construct a BST from a sorted array
Given a sorted integer array A of size n, which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.
Note: If array size is even, take first mid as root.
Input: 7
1 2 3 4 5 6 7
Output: 4 2 1 3 6 5 7 
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

BinaryTreeNode<int>* constructBST(int* input, int s, int e){
	if(s > e){
		return NULL;
	}
	int mid = (s + e)/2;
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
	root->left = constructBST(input, s, mid-1);
	root->right = constructBST(input, mid+1, e);
	return root;
}

void print(BinaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}

int main(){
	int n;
	cout<<"Enter the size: ";
	cin>>n;
	cout<<"Enter the elements: ";
	int* input = new int[n];
	for(int i = 0; i < n; i++){
		cin>>input[i];
	}
	BinaryTreeNode<int>* root = constructBST(input, 0, n-1);
	print(root);
	return 0;
}