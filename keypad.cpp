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

void keypad(int n, string output){
	if(n == 0){
		cout<<output<<endl;
		return;
	}
	int lastDigit = n%10;
	int smallDigit = n/10;
	string option = options(lastDigit);
	int i = 0;
	while(i < option.length()){
		keypad(smallDigit,option[i]+output);
		i++;
	}
	return;
}

int main(){
	int n;
	cout<<"Enter the number: ";
	cin>>n;
	string output;
	keypad(n,output);
	return 0;
}