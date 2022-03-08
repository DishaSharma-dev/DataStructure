/* Construct Tree from Inorder and Postorder
Input: 7
	4 2 5 1 6 3 7 
	4 5 2 6 7 3 1 
Output: 1 
        2 3 
        4 5 6 7 
*/

#include <iostream>
#include <queue>
using namespace std;

template <typename T>

class BinaryTreeNode{
	public:
		T data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;
	BinaryTreeNode(T data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

BinaryTreeNode<int>* construct(int* inorder, int* postorder, int InS, int InE, int PosS, int PosE){
	if(InS > InE){
		return NULL;
	}
	int rootData = postorder[PosE];
	int rootIndex = -1;
	for(int i = InS; i <= InE; i++){
		if(inorder[i] == rootData){
			rootIndex = i;
			break;
		}
	}
	int LInS = InS;
	int LInE = rootIndex - 1;
	int LPosS = PosS;
	int LPosE = LInE - LInS + LPosS;
	int RInS = rootIndex + 1;
	int RInE = InE;
	int RPosS = LPosE + 1;
	int RPosE = PosE - 1;
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	root->left = construct(inorder, postorder, LInS, LInE, LPosS, LPosE);
	root->right = construct(inorder, postorder, RInS, RInE, RPosS, RPosE);
	return root;
}

void printTree(BinaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	while(q.size() != 0){
		BinaryTreeNode<int>* front = q.front();
		cout<<front->data<<": ";
		q.pop();
		if(front->left != NULL){
			cout<<"L: "<<front->left->data;
			q.push(front->left);
		}
		if(front->right != NULL){
			cout<<" R: "<<front->right->data;
			q.push(front->right);
		}
		cout<<endl;
	}
}

int main(){
	cout<<"Enter the size: ";
	int n;
	cin>>n;
	cout<<"Enter the inorder items: ";
	int* inorder = new int[n];
	for(int i = 0; i < n; i++){
		cin>>inorder[i];
	}
	cout<<"Enter the postorder items: ";
	int* postorder = new int[n];
	for(int i = 0; i < n; i++){
		cin>>postorder[i];
	}
	BinaryTreeNode<int>* root = construct(inorder, postorder, 0, n-1, 0, n-1);
	printTree(root);
	return 0;
}