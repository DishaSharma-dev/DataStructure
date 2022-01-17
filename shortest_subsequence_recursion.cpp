/* Shortest Subsequence (Recursive Approach) TC:2^n
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, 
which is not a subsequence in V.
Input: babab
       babba
Output: 3
*/

#include <iostream>
#include <cstring>
using namespace std;

int shortestSubsequence(string str1, string str2, int s1 = 0, int s2 = 0){
	if(s2 == str2.length()){
		return 1;
	}
	if(s1 == str1.length()){
		return 1001;
	}
	int option1 = shortestSubsequence(str1, str2, s1 + 1, s2);
	int idx = -1;
	for(int i = s2; i < str2.length(); i++){
		if(str2[i] == str1[s1]){
			idx = i;
			break;
		}
	}
	if(idx == -1){
		return 1;
	}
	int option2 = 1 + shortestSubsequence(str1, str2, s1 + 1, idx + 1);
	if(option1 < option2){
		return option1;
	}
	else{
		return option2;
	}
}

int main(){
	string str1;
	string str2;
	cout<<"Enter the string1: ";
	cin>>str1;
	cout<<"Enter the string2: ";
	cin>>str2;
	cout<<"Output is: ";
	cout<<shortestSubsequence(str1, str2);
	return 0;
}