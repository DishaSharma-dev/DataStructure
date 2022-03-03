/* Node having the sum of children and node is max 
Input: 5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Output: 1
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode{
	public:
		T data;
		vector<TreeNode<T>*> children;
	TreeNode(T data){
		this->data = data;
	}
};

template <typename T>
class MaxPair{
	public:
		int sum;
		TreeNode<T>* node;
};

TreeNode<int>* takeInput(){
	int data;
	cout<<"Enter data: ";
	cin>>data;
	TreeNode<int>* root = new TreeNode<int>(data);
	queue<TreeNode<int>*> q;
	q.push(root);
	while(q.size() != 0){
		TreeNode<int>* front = q.front();
		q.pop();
		int n, childData;
		cout<<"Enter the number of child "<<front->data<<" have: ";
		cin>>n;
		for(int i = 0; i < n; i++){
			cout<<"Enter data";
			cin>>childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			q.push(child);
		}
	}
	return root;
}

MaxPair<int>* maxSumNode(TreeNode<int>* root){
	if(root == NULL){
		MaxPair<int> *pair = new MaxPair<int>();
		pair->node = NULL;
		pair->sum = INT_MIN;
		return pair;
	}
	int sum = root->data;
	for(int i = 0; i < root->children.size(); i++){
		sum += root->children[i]->data;
	}
	MaxPair<int> *ans = new MaxPair<int>();
	ans->node = root;
	ans->sum = sum;
	for(int i = 0; i < root->children.size(); i++){
		MaxPair<int>* childAns = maxSumNode(root->children[i]);
		if(childAns->sum > ans->sum){
			ans = childAns;
		}
	}
	return ans;
}

TreeNode<int>* maxSum(TreeNode<int> *root){
    return (maxSumNode(root))->node;
}

int main(){
	TreeNode<int>* root = takeInput();
	TreeNode<int>* node = maxSum(root);
	cout<<"Max sum node is: "<<node->data;
	return 0;
}