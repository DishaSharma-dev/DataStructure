/* Even count of odd
Given a binary tree, count and return the number of subtrees which are having even count of odd elements
present in them.
Input: 1 2 3 4 5 6 7  -1 -1 -1 -1 -1 -1 -1 -1
Output: 2
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

int helper(BinaryTreeNode<int>* root, int* pcount){
	if(root == NULL) return 0;
	int c = helper(root->left, pcount);
	c += helper(root->right, pcount);
	if(root->data % 2 != 0) c+=1;
	if(c % 2 == 0 && c != 0) (*pcount)++;
	return c;
}

int even_count_of_odd(BinaryTreeNode<int>* root){
	int count  = 0;
	int *pcount = &count;
	helper(root, pcount);
	return count;
}

int main(){
	BinaryTreeNode<int>* root = takeInput();
	int output = even_count_of_odd(root);
	cout<<output;
	return 0;
}