/* Min and Max of binary tree
Input: 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Output: 1 14
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

pair<int, int> getMinAndMax(BinaryTreeNode<int>* root){
	pair<int, int> ans = make_pair(INT_MAX, INT_MIN);
	if(root == NULL){
		return ans;	
	}
	pair<int, int> leftPair = getMinAndMax(root->left);
	pair<int, int> rightPair = getMinAndMax(root->right);
	ans.first = min(min(leftPair.first, rightPair.first), root->data);
	ans.second = max(max(leftPair.second, rightPair.second), root->data);
	return ans;
}


int main(){
	BinaryTreeNode<int>* root = takeInput();
	pair<int, int> ans = getMinAndMax(root);
	cout<<"Min is: "<<ans.first<<endl;;
	cout<<"Max is: "<<ans.second;
	return 0;
}