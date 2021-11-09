/* Given an input string S and two characters c1 and c2, 
you need to replace every occurrence of character c1 with character c2 in the given string.
Input: abacd
       a x
Output: xbxcd
*/
#include <iostream>
using namespace std;

void replace(char str[100], char str1, char str2) {
	if(str[0] == '\0'){
		return;
	}
	if(str[0] == str1 ){
		str[0] = str2;
	}
	replace(str+1,str1,str2);
}

int main(){
	char str[100];
	char str1;
	char str2;
	cout<<"Enter the string: ";
	cin>>str;
	cout<<"Enter the character to be replaced: ";
	cin>>str1;
	cout<<"Enter the character by which it is replaced: ";
	cin>>str2;
	cout<<"String after replacement is : ";
    replace(str,str1,str2);
    cout<<str;
	return 0;
}
