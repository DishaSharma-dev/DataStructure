/* Compress the String
   input => aaabbeeeeedsa
   output => a3b2e5dsa
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char str[256]={0};
	char input[50];
	cout<<"Enter the string: ";
	cin>>input;
	int len = strlen(input);
	for(int i=0;i<len;i++){
		int index = input[i];
		str[index]++;
	}
	for(int i=0;input[i]!='\0';i++){
		int index = input[i];
		int count = str[index];
		if(str[index]>1){
			cout<<input[i]<<count;
			i = i + (count-1);
		}
		else{
			cout<<input[i];
		}
	}
	return 0;
}