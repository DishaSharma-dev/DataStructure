/* Count leaf nodes */

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

int numLeafNode(TreeNode<int>* root) {
    int count = 0;
    if(root->children.size() == 0){
    	count++;
	}
    for(int i = 0; i < root->children.size(); i++){
        count += numLeafNode(root->children[i]);
    }
    return count;
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
	int count = numLeafNode(root);
	cout<<"No of leaf node is: "<<count;
	return 0;
}