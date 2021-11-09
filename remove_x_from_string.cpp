/* Removing x from the string
Input: xabcx 
Output: abc
*/
#include <iostream>
using namespace std;

void removeX(char str[100]) {
	if(str[0] == '\0'){
		return ;
	}
	if(str[0] != 'x'){
		return removeX(str+1);
	}
	else{
		int i = 1;
		for(; str[i] != '\0'; i++){
			str[i-1] = str[i];
		}
		str[i-1] = str[i];
		return removeX(str);
	}
}

int main(){
	char str[100];
	cout<<"Enter the string: ";
	cin>>str;
	cout<<"String after removing x is : ";
    removeX(str);
    cout<<str;
	return 0;
}
