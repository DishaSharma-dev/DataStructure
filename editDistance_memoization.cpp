/* Edit Distance Memoization Approach 
=> Time Complexity--0(mn)
Input: abc
       dc
Output: 2
Explanation: One insert of a and replace d with b
*/

#include <iostream>
#include <cstring>
using namespace std;

int editDistance(char* s1, char* s2, int** dp){
	int m = strlen(s1);
	int n = strlen(s2);
	if(s1[0] == '\0' && strlen(s2) != 0){
		return strlen(s2);
	}
	if(s2[0] == '\0' && strlen(s1) != 0){
		return strlen(s1);
	}
	if(s1[0] == '\0' && s2[0] == '\0'){
		return 0;
	}
	if(dp[m][n] > -1){
		return dp[m][n];
	}
	if(s1[0] == s2[0]){
		int x = editDistance(s1 + 1, s2 + 1, dp);
		dp[m][n] = x;
	}
	else{
		int option1 = 1 + editDistance(s1, s2 + 1, dp);
		int option2 = 1 + editDistance(s1 + 1, s2, dp);
		int option3 = 1 + editDistance(s1 + 1, s2 + 1, dp);
		int ans = min(option1, min(option2, option3));
		dp[m][n] = ans;
		return dp[m][n];
	}
}

int main(){
	char s1[100];
	char s2[100];
	cin>>s1>>s2;
	int m = strlen(s1);
	int n = strlen(s2);
	int** dp = new int*[m+1];
	for(int i = 0; i <= m; i++){
		dp[i] = new int[n+1];
		for(int j = 0; j <= n; j++){
			dp[i][j] = -1;
		}
	}
	cout<<editDistance(s1, s2, dp);
	for(int i = 0; i <= m; i++){
		delete []dp[i];
	}
	delete []dp;
	return 0;
}