/* Recover BST
Two elements of a Binary Search Tree (BST) are swapped. Tell us the 2 values swapping which the tree
will be restored as a BST.Save the output 2 values in an array and return that array.
Input: 1 2 3 -1 -1 -1 -1
Output: 1 2
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

BinaryTreeNode<int>* first;
BinaryTreeNode<int>* last;
BinaryTreeNode<int>* pre;
BinaryTreeNode<int>* middle;

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

void inorder(BinaryTreeNode<int>* root){
	if(root == NULL) return;
	inorder(root->left);
	if(pre != NULL && root->data < pre->data){
		if(first == NULL){
			first = pre;
			middle = root;
		}
		else{
			last = root;
		}
	}
	pre = root;
	inorder(root->right);
}

vector<int> recoverBST(BinaryTreeNode<int>* root){
	vector<int> output;
	first = last = middle = NULL;
	pre = new BinaryTreeNode<int>(INT_MIN);
	inorder(root);
	if(first && last){
		output.push_back(first->data);
		output.push_back(last->data);
	}
	else if(first && middle){
		output.push_back(first->data);
		output.push_back(middle->data);
	}
	return output;
}

int main(){
	BinaryTreeNode<int>* root = takeInput();
	vector<int> output = recoverBST(root);
	cout<<output[0]<<" "<<output[1];
	return 0;
}