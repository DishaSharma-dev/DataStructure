/* Clear all bits from MSB
You are given two integers N and i. You need to clear all bits from MSB to ith bit 
(start i from right to left) and return the updated N.
Counting of bits starts from 0 from right to left.
Input: 15 2
Output: 3
*/

#include <bits/stdc++.h>
using namespace std;

void check(int n, int i){
	int ans = (1 << i) - 1;
	int output = ans & n;
	cout<<output;
}

int main(){
	int n, i;
	cout<<"Enter the number: ";
	cin>>n;
	cout<<"Enter the value of i: ";
	cin>>i;
	check(n, i);
	return 0;
}
