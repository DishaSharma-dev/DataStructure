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

int takeInput(){
	int data, n;
	int sum;
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
			sum += child;
			TreeNode<int>* childData = new TreeNode<int>(child);
			front->children.push_back(childData);
			q.push(childData);
		}
	}
	sum = sum + root->data;
	return sum;
}

int main(){
	int sum = takeInput();
	cout<<"Sum is: "<<sum;
	return 0;
}