/* Edit Distance DP Approach 
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
	for(int i = 0; i <= m; i++){
		dp[i][0] = i;
	}
	for(int i = 0; i <= n; i++){
		dp[0][i] = i;
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}
			else{
				dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
			}
		}
	}
	return dp[m][n];
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
	}
	cout<<editDistance(s1, s2, dp);
	for(int i = 0; i <= m; i++){
		delete []dp[i];
	}
	delete []dp;
	return 0;
}