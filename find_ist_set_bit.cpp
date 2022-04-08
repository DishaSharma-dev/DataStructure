/* Find 1st set bit
You are given an integer N. You need to return an integer M, in which only one bit is set
which at position of lowest set bit of N (from right to left).
Input: 7
Output: 1
*/

#include <bits/stdc++.h>
using namespace std;

void check(int n){
	int ans = n & (~(n-1));
	cout<<ans;
}

int main(){
	int n, i;
	cout<<"Enter the number: ";
	cin>>n;
	check(n);
	return 0;
}