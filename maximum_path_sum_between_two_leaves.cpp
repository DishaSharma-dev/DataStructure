/* Maximum Path Sum between two leaves 
Input: 10 9 4 3 1 5 8 -1 -1 -1 -1 -1 6 -1 -1 3 -1 -1 -1
Output: 40
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

int max_path = 0;
int maxPath(BinaryTreeNode<int>* root){
	if(root == NULL){
		return 0;
	}
	int l = 0, r = 0;
	if(root->left){
		l = maxPath(root->left);
	}
	if(root->right){
		r = maxPath(root->right);
	}
	if(root->left && root->right){
		max_path =  max(max_path, l + r + root->data);
	}
	return max(l, r) + root->data;
}

int main(){
	BinaryTreeNode<int>* root = takeInput();
	cout<<"Maximum Path Sum between two leaves: ";
	maxPath(root);
	cout<<max_path;
	return 0;
}
