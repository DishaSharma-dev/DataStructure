/* Level wise Linked List
Input: 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Output: 5 
		6 10 
		2 3 
		9
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

template <typename T>
class Node{
	public:
		T val;
		Node* next;
	Node(T val){
		this->val = val;
		this->next = NULL;
	}
};

BinaryTreeNode<int>* takeInput(){
	int data;
	cout<<"Enter data";
	cin>>data;
	if(data == -1){
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	while(q.size() != 0){
		BinaryTreeNode<int>* front = q.front();
		q.pop();
		int leftChild;
		cout<<"Enter the left child of "<<front->data<<": ";
		cin>>leftChild;
		if(leftChild != -1){
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChild);
			front->left = child;
			q.push(child);
		}
		int rightChild;
		cout<<"Enter the right child of "<<front->data<<": ";
		cin>>rightChild;
		if(rightChild != -1){
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChild);
			front->right = child;
			q.push(child);
		}
	}
	return root;
}

vector<Node<int>*> constructLinkedList(BinaryTreeNode<int>* root){
	vector<Node<int>*> ans;
	if(root == NULL){
		return ans;
	}
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
    Node<int>* head = NULL;
    Node<int>* tail = NULL;
    int nextLevelCount = 0;
    int currentLevelCount = 1;
	while(q.size() !=  NULL){
		BinaryTreeNode<int>* front = q.front();
		q.pop();
		Node<int>* newnode = new Node<int>(front->data);
		if(head == NULL){
			head = newnode;
			tail = newnode;
		}
		else{
			tail->next = newnode;
			tail = newnode;
		}
		if(front->left != NULL){
			q.push(front->left);
			nextLevelCount++;
		}
		if(front->right != NULL){
			q.push(front->right);
			nextLevelCount++;
		}
		currentLevelCount--;
		if(currentLevelCount == 0){
			ans.push_back(head);
			head = NULL;
			tail = NULL;
			currentLevelCount = nextLevelCount;
			nextLevelCount = 0;
		}
	}
	return ans;
}

void print(Node<int>* head){
	Node<int>* temp = head;
	while(temp != NULL){
		cout<<temp->val<<" ";
		temp = temp->next;
	}
}


int main(){
	BinaryTreeNode<int>* root = takeInput();
	vector<Node<int>*> output = constructLinkedList(root);
	for(int i = 0; i < output.size(); i++){
		print(output[i]);
		cout<<endl;
	}
	return 0;
}