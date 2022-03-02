/* Print Level Wise*/

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
	queue<TreeNode<int>*> q;
	q.push(root);
	while(q.size() != 0){
		TreeNode<int>* front = q.front();
		q.pop();
		cout<<front->data<<":";
		for(int i = 0; i < front->children.size(); i++){
			if(i < front->children.size()-1){
				cout<<front->children[i]->data<<",";
			}
			else{
				cout<<front->children[i]->data;
			}
			q.push(front->children[i]);
		}
		cout<<endl;
	}
}

int main(){
	TreeNode<int>* root = takeInput();
	printTree(root);
	return 0;
}