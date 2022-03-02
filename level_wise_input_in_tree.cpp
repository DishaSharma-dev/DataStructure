/* Level wise input in tree */

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

void printTree(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<":";
	for(int i = 0; i < root->children.size(); i++){
		cout<<root->children[i]->data<<",";
	}
	cout<<endl;
	for(int i = 0; i < root->children.size(); i++){
		printTree(root->children[i]);
	}
}

int main(){
	TreeNode<int>* root = takeInput();
	printTree(root);
	return 0;
}