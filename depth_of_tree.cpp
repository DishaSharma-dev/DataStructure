/* Depth of tree */

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

int getDepth(TreeNode<int>* root) {
    int depth = 0;
    for(int i = 0; i < root->children.size(); i++){
        int childDepth = getDepth(root->children[i]);
        depth = max(depth, childDepth);
    }
    return depth+1;
}

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

int main(){
	TreeNode<int>* root = takeInput();
	int depth = getDepth(root);
	cout<<"Depth of node is: "<<depth-1;
	return 0;
}