/* Turn off 1st set bit
You are given an integer Ni. You need to make first set bit of binary representation of N to 0
and return the updated N.
Counting of bits start from 0 from right to left.
Input: 4
Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

void check(int n){
	int ans = n & (n-1);
	cout<<ans;
}

int main(){
	int n, i;
	cout<<"Enter the number: ";
	cin>>n;
	check(n);
	return 0;
}