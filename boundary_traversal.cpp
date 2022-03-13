/* Boundary Traversal
Input: 1 2 3 4 5 7 -1 -1 -1 6 -1 -1 8 -1 -1 -1 -1
Output: 1 2 4 6 8 7 3
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

void printLeftBoundary(BinaryTreeNode<int>* root, vector<int>& output){
	BinaryTreeNode<int>* curr = root->left;
	while(curr){
		if(curr->left || curr->right) output.push_back(curr->data);
		if(curr->left) curr = curr->left;
		else curr = curr->right;
	}
}

void printLeaves(BinaryTreeNode<int>* root, vector<int>& output){
	if(!(root->left) && !(root->right)){
		output.push_back(root->data);
	}
	if(root->left) printLeaves(root->left, output);
	if(root->right) printLeaves(root->right, output);
}

void printRightBoundary(BinaryTreeNode<int>* root, vector<int>& output){
	BinaryTreeNode<int>* curr = root->right;
	vector<int> temp;
	while(curr){
		if(curr->left || curr->right) temp.push_back(curr->data);
		if(curr->right) curr = curr->right;
		else curr = curr->left;
	}
	for(int i = temp.size()-1; i>= 0; i--){
		output.push_back(temp[i]);
	}
}

void printBoundary(BinaryTreeNode<int>* root, vector<int>& output){
	if(root == NULL){
		return;
	}
	if(root->left || root->right){
		output.push_back(root->data);	
	}
	printLeftBoundary(root, output);
	printLeaves(root, output);
	printRightBoundary(root, output);
}

int main(){
	BinaryTreeNode<int>* root = takeInput();
	vector<int> output;
	printBoundary(root, output);
	for(int i = 0; i < output.size(); i++){
		cout<<output[i]<<endl;
	}
	return 0;
}
