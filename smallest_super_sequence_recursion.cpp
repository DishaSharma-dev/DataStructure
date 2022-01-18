/*Smallest Super Sequence
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
	if(n == 0 || m == 0){
		return n+m;	
	}
	if(str1[n-1] == str2[m-1]){
		return 1 + superSequence(str1, str2, n-1, m-1);
	}
	else{
		return 1 + min(superSequence(str1, str2, n-1, m), superSequence(str1, str2, n, m-1));
	}
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