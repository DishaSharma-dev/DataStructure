/* Return Keypad Code
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Input: 2 3
Output: ad
ae
af
bd
be
bf
cd
ce
cf */

#include <iostream>
#include <cstring>
using namespace std;

string options(int d){
	if(d == 2){
		return "abc";
	}
	else if(d == 3){
		return "def";
	}
	else if(d == 4){
		return "ghi";
	}
	else if(d == 5){
		return "jkl";
	}
	else if(d == 6){
		return "mno";
	}
	else if(d == 7){
		return "pqrs";
	}
	else if(d == 8){
		return "tuv";
	}
	else if(d == 9){
		return "wxyz";
	}
	return " ";
}

int keypad(int n, string output[]){
	if(n == 0){
		output[0] = "";
		return 1;
	}
	int lastDigit = n%10;
	int smallDigit = n/10;
	int smallOutputSize = keypad(smallDigit,output);
	string option = options(lastDigit);
	for(int i = 0; i < option.length()-1; i++){
		for(int j = 0; j < smallOutputSize; j++){
			output[j + (i + 1) * smallOutputSize] =  output[j];
		}
	}
	int k= 0;
	for(int i = 0; i < option.length(); i++){
		for(int j = 0; j < smallOutputSize; j++){
			output[k] = output[k] + option[i];
			k++;
		}
	}
	return smallOutputSize*option.length();
}

int main(){
	int n;
	cout<<"Enter the number: ";
	cin>>n;
	string output[1000];
	int count = keypad(n,output);
	for(int i = 0; i < count; i++){
		cout<<output[i]<<endl;
	}
	return 0;
}