/*Replace pi (Recursive)
Input: pip
Output: 3.14p
*/

#include <iostream>
#include <cstring>
using namespace std;

char* replacePI(char str[]){
	if(strlen(str) == 0 || strlen(str) == 1){
		return 0;
	} 
	replacePI(str+1);
	if(str[0] == 'p' && str[1] == 'i'){
		for(int i = strlen(str)+2; i>0; i--){
			str[i]=str[i-2];
		}
		str[0] = '3';
		str[1] = '.';
		str[2] = '1';
		str[3] = '4';
	}
	return str;
}

int main(){
	char str[100];
	cout<<"Enter the string";
	cin>>str;
	cout<<"Output is: ";
	cout<<replacePI(str);
	return 0;
}