/* Longest leaf to root path 
Input: 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Output: 9
		3
		6
		5
*/

#include <iostream>
#include <queue>
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

vector<int> longestPath(BinaryTreeNode<int>* root){
	if(root == NULL){
		vector<int> ans;
		return ans;
	}
	if(!root->left && !root->right){
		vector<int> output;
		output.push_back(root->data);
		return output;
	}
	vector<int> leftAns = longestPath(root->left);
	vector<int> rightAns = longestPath(root->right);
	if(leftAns.size() == 0){
		rightAns.push_back(root->data);
		return rightAns;
	}
	else if(rightAns.size() == 0){
		leftAns.push_back(root->data);
		return leftAns;
	}
	else{
		if(leftAns.size() < rightAns.size()){
			rightAns.push_back(root->data);
			return rightAns;
		}
		else{
			leftAns.push_back(root->data);
			return leftAns;
		}
	}
}

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

int main(){
	BinaryTreeNode<int>* root = takeInput();
	vector<int> output = longestPath(root);
	for(int i = 0; i < output.size(); i++){
		cout<<output[i]<<endl;
	}
	return 0;
}