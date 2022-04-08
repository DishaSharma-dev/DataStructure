/* Unset ith bit
You are given two integers N and i. You need to make ith bit of binary representation of N to 0
and return the updated N.
Counting of bits start from 0 from right to left.
Input: 7 2
Output: 3
*/

#include <bits/stdc++.h>
using namespace std;

void unsetIthBit(int n, int i){
	int ans = n & (~(1 << i));
	cout<<ans;
}

int main(){
	int n, i;
	cout<<"Enter the number: ";
	cin>>n;
	cout<<"Enter the value of i";
	cin>>i;
	unsetIthBit(n, i);
	return 0;
}