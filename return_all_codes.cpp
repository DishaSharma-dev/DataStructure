/* Return All codes  (string)
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. 
Write a program to return the list of all possible codes that can be generated from the given string.
Input: 1123
Output: aabc
        kbc
        alc
        aaw
        kw
*/
#include <iostream>
#include <cstring>
using namespace std;

int codes(string str, string output[]){
	if(str[0] == '\0'){
		output[0] = "";
		return 1;
	}
	int size1,size2;
    int first = str[0] - 48;
    char firstChar = first + 'a' - 1;
    char secondChar = '\0';
    string smallOutput1[500];
    string smallOutput2[500];
    size1 = codes(str.substr(1),smallOutput1);
    if(str[1] != '\0'){
    	int second = first*10 + str[1] - 48;
        if(second >= 10 && second <= 26){
    		secondChar = second + 'a' - 1;
        	size2 = codes(str.substr(2),smallOutput2);
	    }
	}
	int k = 0;
	for(int  i = 0; i < size1; i++){
		output[k] = firstChar + smallOutput1[i];
		k++;
	} 
	for(int i = 0; i < size2; i++){
		output[k] = secondChar + smallOutput2[i];
		k++;
	}
	return k;
}

int main(){
	string str;
	cout<<"Enter the string: ";
	cin>>str;
	string output[1000];
	int size = codes(str,output);
	for(int i = 0; i < size; i++){
		cout<<output[i]<<endl;
	}
	return 0;
}