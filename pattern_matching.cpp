/* Pattern Matching
Given a list of n words and a pattern p that we want to search.
Check if the pattern p is present the given words or not. Return true if the pattern is present and 
false otherwise.
Input: 4
abc def ghi cba
de
Output: true
*/

#include <iostream>
using namespace std;

class TrieNode{
	public:
		char data;
		TrieNode** children;
		
	TrieNode(char data){
		this->data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++){
			children[i] = NULL;
		}
	}
};

class Trie{
	TrieNode* root;
	public:
	Trie(){
		root = new TrieNode('\0');
	}
	
	void insert(TrieNode* root, string word){
		if(word.size() == 0) return;
		int index = word[0] - 'a';
		TrieNode* child;
		if(root->children[index] != NULL){
			child = root->children[index];
		}
		else{
			child = new TrieNode(word[0]);
			root->children[index] = child;
		}
		insert(child, word.substr(1));
	}
	
	void insert(string word){
		for(int i = 0; i < word.length(); i++){
			insert(root, word.substr(i));
		}
	}
	
	bool search(TrieNode* root, string word){
		if(word.length() == 0){
			return true;
		}
		int index = word[0] - 'a';
		TrieNode* child;
		if(root->children[index] == NULL){
			return false;
		}
		child = root->children[index];
		return search(child, word.substr(1));
	}
	
	bool search(string word){
		return search(root, word);
	}
};

int main(){
	int n;
	cout<<"Enter the number: ";
	cin>>n;
	Trie t;
	for(int i = 0; i < n; i++){
		string str;
		cin>>str;
		t.insert(str);
	}
	string str2;
	cout<<"Enter the word to search: ";
	cin>>str2;
	cout<<t.search(str2);
	return 0;
}