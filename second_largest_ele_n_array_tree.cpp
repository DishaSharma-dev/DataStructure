/* Second Largest Element in tree 
Input: 10 3 20 30 40 2 40 50 0 0 0 0 
Output: 40
*/

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

template <typename T>
class custom{
	public:
		TreeNode<T>* max;
		TreeNode<T>* smax;
	custom(TreeNode<T>* first, TreeNode<T>* second){
		this->max = first;
		this->smax = second;
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

custom<int>* secondLargestElement(TreeNode<int>* root){
	if(root == NULL){
		custom<int>* ans = new custom<int>(NULL, NULL);
		return ans;
	}
	custom<int>* ans = new custom<int>(root, NULL);
	for(int i = 0; i < root->children.size(); i++){
		custom<int>* childAns = secondLargestElement(root->children[i]);
		if(childAns->max->data > ans->max->data){
			if(childAns->smax == NULL){
				ans->smax = ans->max;
				ans->max = childAns->max;
			}
			else{
				if(childAns->smax->data > ans->max->data){
					ans->smax = childAns->smax;
					ans->max = childAns->max;
				}
				else{
					ans->smax = ans->max;
					ans->max = childAns->max;
				}
			}
		}
		else if(childAns->max->data == ans->max->data && childAns->smax != NULL){
			if(ans->smax == NULL || ans->smax->data < childAns->smax->data){
				ans->smax = childAns->smax;
			}
		}
		else if(childAns->max->data != ans->max->data && (ans->smax == NULL || childAns->max->data > ans->smax->data)){
			ans->smax = childAns->max;
		}
	}
	return ans;
}

int main(){
	TreeNode<int>* root = takeInput();
	custom<int>* ele = secondLargestElement(root);
	cout<<"Second Largest element is: "<<ele->smax->data;
	return 0;
}