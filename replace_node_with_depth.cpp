/* Replace Node with depth */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode{
	public:
		T data;
		vector<TreeNode<T>*>children;
	TreeNode(T data){
		this->data = data;
	}
};

TreeNode<int>* takeInput(){
	int data, n;
	cout<<"Enter the data: ";
	cin>>data;
	TreeNode<int>* root = new TreeNode<int>(data);
	queue<TreeNode<int>*> q;
	q.push(root);
	while(q.size() != 0){
		TreeNode<int>* front = q.front();
		q.pop();
		cout<<"Enter the number of children "<<front->data<<" have: ";
		int n;
		cin>>n;
		for(int i = 0; i < n; i++){
			cout<<"Enter data: ";
			int child;
			cin>>child;
			TreeNode<int>* childData = new TreeNode<int>(child);
			front->children.push_back(childData);
			q.push(childData);
		}
	}
	return root;
}

void replaceNode(TreeNode<int>* root, int depth){
	if(root == NULL){
		return;
	}
	root->data = depth;
	for(int i = 0; i < root->children.size(); i++){
		replaceNode(root->children[i], depth + 1);
	}
}

void printTree(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	queue<TreeNode<int>*> q;
	q.push(root);
	while(q.size() != 0){
		TreeNode<int>* front = q.front();
		q.pop();
		cout<<front->data<<" ";
		for(int i = 0; i < front->children.size(); i++){
			q.push(front->children[i]);
		}
		cout<<endl;
	}
}

int main(){
	TreeNode<int>* root = takeInput();
	replaceNode(root, 0);
	printTree(root);
	return 0;
}