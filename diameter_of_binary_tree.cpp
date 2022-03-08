/* Diameter of binary tree 
Input: 1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1
Output: 6
*/

/* Preorder Binary Tree */

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


pair<int, int> heightDiameter(BinaryTreeNode<int>* root){
	if(root == NULL){
		pair<int, int> ans;
		ans.first = 0;
		ans.second = 0;
		return ans;
	}
	pair<int, int> leftAns = heightDiameter(root->left);
	pair<int, int> rightAns = heightDiameter(root->right);
	int ld = leftAns.second;
	int lh = leftAns.first;
	int rd = rightAns.second;
	int rh = rightAns.first;
	int height = max(lh, rh) + 1;
	int diameter = max(lh + rh, max(ld, rd));
	pair<int, int> ans;
	ans.first = height;
	ans.second = diameter;
	return ans;
}

int main(){
	BinaryTreeNode<int>* root = takeInput();
	pair<int, int> ans = heightDiameter(root);
	cout<<"Height of tree is: "<<ans.first<<endl;;
	cout<<"Diameter of tree is: "<<ans.second;
	return 0;
}