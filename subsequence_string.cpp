/* Subsequence of string */

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int subseq(string str, string output[]){
	if(str.empty()){
		output[0] = " ";
		return 1;
	}
	string str1 = str.substr(1);
	int smallOutputSize = subseq(str1,output);
	for(int i = 0; i < smallOutputSize; i++){
		output[i+smallOutputSize] = str[0] + output[i];
	}
	return 2*smallOutputSize;
}

int main(){
	string str;
	cout<<"Enter the string: ";
	cin>>str;
	int len = str.size();
	int size = pow(2,len);
	string* output = new string[size];
	int count = subseq(str,output);
	for(int i = 0; i < count; i++){
		cout<<output[i]<<endl;
	}
	return 0;
}