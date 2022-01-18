/* Shortest Subsequence (DP Approach) TC:m*n^2
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, 
which is not a subsequence in V.
Input: babab
       babba
Output: 3
*/

#include <iostream>
#include <cstring>
#define max 1005
using namespace std;

int shortestSubsequence(char* str1, char* str2){
	int n = strlen(str1);
	int m = strlen(str2);
	int dp[n + 1][m + 1];
	for(int i = 0; i <= n; i++){
		dp[i][0] = 1;
	}
	for(int i = 0; i <= m; i++){
		dp[0][i] = max;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int k;
			char ch = str1[i-1];
			for(k = j-1; k >=0; k--){
				if(ch == str2[k]){
					break;
				}
			}
			if(k == -1){
				dp[i][j] = 1;
			}
			else{
				dp[i][j] = min(dp[i-1][j], dp[i-1][k] + 1);
			}
		}
	}
	int ans = dp[n][m];
	if(ans >= INT_MAX){
		ans = -1;
	}
	return ans;
}

int main(){
	char str1[100];
	char str2[100];
	cout<<"Enter the string1: ";
	cin>>str1;
	cout<<"Enter the string2: ";
	cin>>str2;
	cout<<"Output is: ";
	cout<<shortestSubsequence(str1, str2);
	return 0;
}