/* Next Larger Element */

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

TreeNode<int>* nextLargerElement(TreeNode<int>* root, int n) {
	if(root == NULL){
		return root;
	}
	TreeNode<int>* nextLarger = NULL;
	if(root->data > n){
		nextLarger = root;
	}
    for(int i = 0; i < root->children.size(); i++){
        TreeNode<int>* temp = nextLargerElement(root->children[i], n);
        if(nextLarger == NULL){
        	nextLarger = temp;
		}
		else if(temp != NULL && temp->data < nextLarger->data){
			nextLarger = temp;
		}
    }
    return nextLarger;
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
	int n;
	cout<<"Enter the element: ";
	cin>>n;
	TreeNode<int>* root = takeInput();
	TreeNode<int>* next = nextLargerElement(root, n);
	cout<<next->data;
	return 0;
}