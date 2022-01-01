/* Longest Increasing Subsequence (LCS) Recursive Approach 
=> Time Complexity--Exponential*/

#include <iostream>
using namespace std;

int lcs(char* s1, char* s2){
	if(s1[0] == '\0' || s2[0] == '\0'){
		return 0;
	}
	if(s1[0] == s2[0]){
		return 1 + lcs(s1 + 1, s2 + 1);
	}
	else{
		int option1 = lcs(s1 + 1, s2);
		int option2 = lcs(s1, s2 + 1);
		return max(option1, option2);
	}
}

int main(){
	char s1[100];
	char s2[100];
	cin>>s1>>s2;
	cout<<lcs(s1,s2);
	return 0;
}