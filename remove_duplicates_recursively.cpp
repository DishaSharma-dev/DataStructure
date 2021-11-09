/* Remove Duplicates Recursively 
Given a string S, remove consecutive duplicates from it recursively
Input: aabccba
Output: abcba
*/
#include <iostream>
#include <cstring>
using namespace std;

void remove_duplicates(char str[100]) {
	int len = strlen(str);
	if(len == 0){
		return;
	}
	if(str[0] == str[1]){
		int i = 1;
		for(; str[i] != '\0'; i++){
			str[i-1] = str[i];
		}
		str[i-1] = str[i];
		remove_duplicates(str);
	}
	remove_duplicates(str + 1);
}

int main(){
	char str[100];
	cout<<"Enter the string: ";
	cin>>str;
	cout<<"After removal string is : ";
    remove_duplicates(str);
    cout<<str;
	return 0;
}
