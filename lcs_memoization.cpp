/*LCS (Memoization Approach)
Time Complexity => 0(mn)
m=> length of string1
n=> length of string2
*/

#include <iostream>
#include <cstring>
using namespace std;

int lcs(char* s1, char* s2, int m, int n, int**dp){
	if(m == 0 || n == 0){
		return 0;
	}
	if(dp[m][n] > -1){
		return dp[m][n];
	}
	if(s1[0] == s2[0]){
		return 1 + lcs(s1 + 1, s2 + 1, m - 1, n - 1, dp);
	}
	else{
		int option1 = lcs(s1 + 1, s2, m - 1, n, dp);
		int option2 = lcs(s1, s2 + 1, m, n-1, dp);
		int ans =  max(option1, option2);
		dp[m][n] = ans;
		return ans;
	}
}

int main(){
	char s1[100];
	char s2[100];
	cin>>s1;
	cin>>s2;
	int m = strlen(s1);
	int n = strlen(s2);
	int** dp = new int*[m+1];
	for(int i = 0; i < m; i++){
		dp[i] = new int[n+1];
		for(int j = 0; j <= n; j++){
			dp[i][j] = -1;
		}
	}
	cout<<lcs(s1, s2, m, n, dp);
	for(int i = 0; i <= m; i++){
		delete []dp[i];
	}
	delete []dp;
	return 0;
}