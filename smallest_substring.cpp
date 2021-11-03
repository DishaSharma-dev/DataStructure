#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

int main() {
	char string1[200];
	char string2[200];
	cout<<"Enter the string1: ";
	cin.getline(string1,200);
	cout<<"Enter the string2: ";
	cin.getline(string2,200);
	unordered_map<char,int> m;
	int large = strlen(string1);
	int small = strlen(string2);
	for(int i = 0; i < small; i++){
		if(m.count(string2[i])  > 0){
			m[string2[i]]++;
		}
		else{
			m[string2[i]] = 1;
		}
	}
	int currentSubstringStart = 0;
	int currentSubstringEnd = 0;
	int answerStart= 0;
	int answerEnd = -1;
	int answerLength = INT_MAX;
	int numRemainingChar = m.size();
	while(currentSubstringEnd < large){
		char currentChar = string1[currentSubstringEnd];
		int charFreq = (m.count(currentChar) > 0) ? m[currentChar] : INT_MIN;
		if(charFreq == INT_MIN) {
			currentSubstringEnd++;
		}
		else {
			m[currentChar] = charFreq - 1;
			if(charFreq == 1) {
				numRemainingChar--;
			}
			if(numRemainingChar == 0) {
				while(currentSubstringStart <= currentSubstringEnd){
					char ch = string1[currentSubstringStart];
					int freq = (m.count(ch)) ? m[ch] : INT_MIN;
					if(freq == INT_MIN){
						currentSubstringStart++;
					}
					else if(freq < 0){
						currentSubstringStart++;
						m[ch] = freq + 1;
					}
					else {
						int currentSubstringLength = currentSubstringEnd - currentSubstringStart + 1;
						if(currentSubstringLength < answerLength){
							answerStart = currentSubstringStart;
							answerEnd = currentSubstringEnd;
							answerLength = currentSubstringLength;
						}
						break;
					}
				}
			}
			currentSubstringEnd++;
		}
	}
	int minLength = answerEnd - answerStart + 1;
	char *output = new char[minLength + 1];
	int j = 0;
	for(int i = answerStart; i < answerStart + minLength; i++, j++){
		output[j] = string1[i];
	}
	output[j] = '\0';
	cout<<output;
	return 0;
}