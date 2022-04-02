/* Check Postorder Squence of BST 
Given an integer array of size N, you need to determine if it is a post-order traversal sequence of a binary
tree or not. Return true if it is post-order traversal of some BST otherwise return false.
Input: 7
	   5 7 6 9 11 10 8
Output: true
*/

#include <bits/stdc++.h>
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

bool check_postorder_sequence(int* arr, int n){
	if(n == 0) return false;
	int root = arr[n-1];
	int i = 0;
	for(; i < n-1; i++){
		if(arr[i] > root){
			break;
		}
	}
	int j = i;
	for(; j < n-1; j++){
		if(arr[j] < root) return false;
	}
	bool left = true;
	if(i > 0){
		left = check_postorder_sequence(arr, i);
	}
	bool right = true;
	if(i < n-1){
		right = check_postorder_sequence(arr + i, n - i - 1);
	}
	return left && right;
}


int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int* arr = new int[n];
	cout<<"Enter the elements: ";
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	int output = check_postorder_sequence(arr, n);
	(output == 1) ? cout<<"true" : cout<<"false";
	return 0;
} 