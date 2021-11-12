//Count the vowel substring of a string
#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

bool isVowel(char ch){
	if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
		return true;
	}
	return false;
}

int count(string word, int k){
	int count = 0;
	int j = 0;
	unordered_map<char , int> map;
	int n = word.length();
	for(int i = 0; i < n; i++){
		if(!isVowel(word[i])) {
			map.clear();
			j = i + 1;
			continue;
		}
		map[word[i]]++;
		while(map.size() > k) {
			map[word[j]]--;
			if(map[word[j]] == 0){
				map.erase(word[j]);
			}
			j++;
		}
		count += i - j + 1;
	}
	return count;
}

int main(){
	string word;
	cout<<"Enter the string: ";
	cin>>word;
	cout<<"The number of substrings are: ";
	int output = count(word , 5) - count(word , 4);
	cout<<output;
	return 0;
}