/*Reverse each word of string
Ex: I am Disha
    ahsid ma I
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char str[500];
	cout<<"Enter the string: ";
	cin.getline(str,500);
	int len = strlen(str);
	int end , start = 0;
	for(int i=0; i<len; i++){
		if(str[i] == ' ' || i == len-1){
			i == len-1 ? end = i : end = i-1;
		while(start < end){
			char temp = str[end];
			str[end] = str[start];
			str[start] = temp;
			start++;
			end--;
		   }
		i == len-1 ? start = 0 : start = i+1;
     	}
	}
	cout<<str;
	return 0;
}
