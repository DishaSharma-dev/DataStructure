/* Check power of 4
You are given an integer N. You need to check if N is power of 4 or not. Return true or false accordingly.
Input: 4
Output: true
*/

#include <bits/stdc++.h>
using namespace std;

void check(int n){
	if(n != 0 && ((n & (n-1)) == 0) && !(n & 0xAAAAAAAA))
		cout<<"true";
	else cout<<"false";
}

int main(){
	int n, i;
	cout<<"Enter the number: ";
	cin>>n;
	check(n);
	return 0;
}