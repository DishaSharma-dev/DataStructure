/*Smallest Super Sequence(DP Approach) TC: n*m
Given two strings S and T with lengths M and N. Find and return the length of their shortest 'Super Sequence.
The shortest 'Super Sequence' of two strings is defined as the smallest string possible that will have
both the given strings as its subsequences.
Input: ab
       ac
Output: 3
Explanation: Their smallest super sequence can be "abc" which has length = 3.*/

#include <iostream>
#include <cstring>
using namespace std;

int superSequence(string str1, string str2, int n, int m){
	int dp[m+1][n+1];
	int count = m;
	for(int i = 0; i <= m; i++){
		dp[i][n] = count;
		count--;
	}
	count = n;
	for(int i = 0; i <= n; i++){
		dp[m][i] = count;
		count--;
	}
	for(int i = m-1; i >= 0; i--){
		for(int j = n - 1; j >= 0; j--){
			if(str1[j] == str2[i]){
				dp[i][j] = 1 + dp[i+1][j+1];
			}
			else{
				dp[i][j] = 1 + min(dp[i+1][j], dp[i][j+1]);
			}
		}
	}
	return dp[0][0];
}

int main(){
	string str1;
	string str2;
	cout<<"Enter the string1: ";
	cin>>str1;
	cout<<"Enter the string2: ";
	cin>>str2;
	cout<<"Output is: ";
	int n = str1.length();
	int m = str2.length();
	cout<<superSequence(str1, str2, n, m);
	return 0;	
}