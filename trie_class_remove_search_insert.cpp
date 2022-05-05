/* Tries Class with insert, search and remove */

#include <iostream>
using namespace std;

class TrieNode{
	public:
		char data;
		TrieNode** children;
		bool isTerminal;
	TrieNode(char data){
		this->data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++){
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie{
	TrieNode* root;
	public:
	Trie(){
		root = new TrieNode('\0');
	}
	
	void insertHelper(TrieNode* root , string word){
		// Base Case
		if(word.length() == 0){
			root->isTerminal = true;
			return;
		}
		// Small Calculation
		int index = word[0] - 'a';
		TrieNode* child;
		if(root->children[index] != NULL){
			child = root->children[index];
		}
		else{
			child = new TrieNode(word[0]);
			root->children[index] = child;
		}
		// Recursive Call
		insertHelper(child, word.substr(1));
	}
	
	void insert(string word){
		insertHelper(root, word);
	}
	
	bool searchHelper(TrieNode* root , string word){
		// Base Case
		if(word.length() == 0){
			return root->isTerminal;
		}
		// Small Calculation
		int index = word[0] - 'a';
		TrieNode* child;
		if(root->children[index] != NULL){
			child = root->children[index];
		}
		else{
			return false;
		}
		// Recursive Call
		return searchHelper(child, word.substr(1));
	}
	
	bool search(string word){
		return searchHelper(root, word);
	}
	
	void removeHelper(TrieNode* root , string word){
		// Base Case
		if(word.length() == 0){
			root->isTerminal = false;
			return;
		}
		// Small Calculation
		int index = word[0] - 'a';
		TrieNode* child;
		if(root->children[index] != NULL){
			child = root->children[index];
		}
		else{
			return;
		}
		// Recursive Call
		removeHelper(child, word.substr(1));
		if(child->isTerminal == false){
			for(int i = 0; i < 26; i++){
				if(child->children[i] != NULL) return;
			}
			delete child;
			root->children[index] = NULL;
		}
	}
	
	void remove(string word){
		return removeHelper(root, word);
	}
};

int main(){
	Trie t;
	t.insert("and");
	t.insert("are");
	t.insert("dot");
	cout<<t.search("and")<<endl;
	t.remove("and");
	cout<<t.search("and")<<endl;
	return 0;
}