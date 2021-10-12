/* Make Strings Anagram
Given two strings S1 and S2, find and return the minimum number of deletions to be made
(total count of deletions in both strings) in order to make the strings anagram.
Input => cde 
         abc
Ouput => 4
*/

#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

int main() {
	char str1[100];
	char str2[100];
	int count = 0;
	cout<<"Enter the string1: ";
	cin>>str1;
	cout<<"Enter the string2: ";
	cin>>str2;
	unordered_map<char,int> map;
	for(int i = 0; str1[i] != '\0'; i++){
		map[str1[i]]++;
	}
	for(int i = 0; str2[i] != '\0'; i++){
		map[str2[i]]++;
	}
	unordered_map<char,int> :: iterator it = map.begin();
	while(it != map.end()) {
		if((it->second % 2) != 0)
			count++;
		it++;
	}
	cout<<count;
}