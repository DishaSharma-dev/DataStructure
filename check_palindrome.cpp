/* Check Palindrome
Check whether a given String S is a palindrome using recursion. Return true or false
Input: racecar
Output: true
*/
#include <iostream>
#include <cstring>
using namespace std;

int check_palindrome(char str[100], int start , int end){
	if(start >=  end){
		return 1;
	}
	else if(str[start] == str[end]){
		return check_palindrome(str, start + 1, end - 1);
	}
	else{
		return 0;
	}
}

int main(){
	char str[100];
	cout<<"Enter the string: ";
	cin>>str;
	int n =  strlen(str);
    int output = check_palindrome(str, 0 , n-1);
    (output == 1) ? cout<<"true" : cout<<"false";
	return 0;
}
