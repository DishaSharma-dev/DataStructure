//Reverse the string word wise

#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char str[500];
	cout<<"Enter the string: ";
	cin.getline(str,500);
	int start = 0;
	int end;
	int len = strlen(str);
	for(int i=0; str[i]!='\0';i++){
		if(str[i] == ' ' || i == len-1){
			i == len-1 ? end = i : end = i-1;
			while(start < end){
				char temp = str[start];
				str[start] = str[end];
				str[end] = temp;
				start++;
				end--;	
			}
		start = i+1;
		}
	}
	for(int i=len-1; i>=0;i--)
	cout<<str[i];
}
