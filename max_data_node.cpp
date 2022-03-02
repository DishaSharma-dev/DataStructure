/*Max Data Node*/

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
	int max_data = INT_MIN;
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
			if(max_data < child){
				max_data = child;
			}
			TreeNode<int>* childData = new TreeNode<int>(child);
			front->children.push_back(childData);
			q.push(childData);
		}
	}
	if(max_data < root->data){
		max_data = root->data;
	}
	return max_data;
}

int main(){
	int max_node = takeInput();
	cout<<"Max node data is: "<<max_node;
	return 0;
}