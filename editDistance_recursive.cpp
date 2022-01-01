/* Edit Distance Recursive Approach 
=> Time Complexity--Exponential
Input: abc
       dc
Output: 2
Explanation: One insert of a and replace d with b
*/

#include <iostream>
#include <cstring>
using namespace std;

int editDistance(char* s1, char* s2){
	if(s1[0] == '\0' && strlen(s2) != 0){
		return strlen(s2);
	}
	if(s2[0] == '\0' && strlen(s1) != 0){
		return strlen(s1);
	}
	if(s1[0] == '\0' && s2[0] == '\0'){
		return 0;
	}
	if(s1[0] == s2[0]){
		return editDistance(s1 + 1, s2 + 1);
	}
	else{
		int option1 = 1 + editDistance(s1, s2 + 1);
		int option2 = 1 + editDistance(s1 + 1, s2);
		int option3 = 1 + editDistance(s1 + 1, s2 + 1);
		return min(option1, min(option2, option3));
	}
}

int main(){
	char s1[100];
	char s2[100];
	cin>>s1>>s2;
	cout<<editDistance(s1,s2);
	return 0;
}