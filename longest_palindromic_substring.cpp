/*Longest Palindromic Substring*/

#include <iostream>
#include <cstring>
using namespace std;

void longestPalindromicSubstring(string str){
	int n = str.length();
	int dp[n][n];
	int x,y,maxlen = INT_MIN;
	for(int i = n-1; i >=0; i--){
		for(int j = i; j <= n-1; j++){
			if(i == j){
				dp[i][j] = 1;
			}
			else if(str[i] == str[j]){
				if(j-i == 1) dp[i][j] = 1;
				else
					dp[i][j] = dp[i+1][j-1];
			}
			if(dp[i][j] == 1 && (j-i) >= maxlen){
				maxlen = j-i;
				x = i;
				y = j;
			}
		}
	}
	cout<<str.substr(x,y-x+1);
}

int main(){
	string str;
	cout<<"Enter the string";
	cin>>str;
	longestPalindromicSubstring(str);
	return 0;
}