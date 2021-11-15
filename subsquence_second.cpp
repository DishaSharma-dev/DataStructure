/* Subsequence of string */

#include <iostream>
#include <cstring>
using namespace std;

void subseq(string str, string output){
	if(str.empty()){
		cout<<output<<endl;
		return;
	}
	string str1 = str.substr(1);
	subseq(str1,output);
	subseq(str1,output + str[0]);
}

int main(){
	string str;
	cout<<"Enter the string: ";
	cin>>str;
	string output = "";
	subseq(str,output);
	return 0;
}