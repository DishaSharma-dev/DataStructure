/* Height of tree */

/* Find Sum of all nodes */

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

int getHeight(TreeNode<int>* root) {
    int height = 0;
    for(int i = 0; i < root->children.size(); i++){
        int childHeight = getHeight(root->children[i]);
        if(childHeight > height){
            height = childHeight;
        }
    }
    return height + 1;
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
	int height = getHeight(root);
	cout<<"Height of tree is: "<<height;
	return 0;
}